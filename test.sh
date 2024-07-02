#!/usr/bin/env bash

#####################################################################
# Credit to `torokmark`: https://github.com/torokmark/assert.sh/blob/main/assert.sh

if command -v tput &>/dev/null && tty -s; then
  RED=$(tput setaf 1)
  YELLOW=$(tput setaf 3)
  GREEN=$(tput setaf 2)
  MAGENTA=$(tput setaf 5)
  NORMAL=$(tput sgr0)
  BOLD=$(tput bold)
else
  RED=$(echo -en "\e[31m")
  YELLOW=$(echo -en "\e[33m")
  GREEN=$(echo -en "\e[32m")
  MAGENTA=$(echo -en "\e[35m")
  NORMAL=$(echo -en "\e[00m")
  BOLD=$(echo -en "\e[01m")
fi

log_header() {
  printf "${BOLD}${MAGENTA}==========  %s  ==========${NORMAL}\n\n" "$@" >&2
}

log_success() {
  printf "${GREEN}✔ %s${NORMAL}\n" "$@" >&2
}

log_warning() {
  printf "${YELLOW}✖ %s${NORMAL}\n" "$@" >&2
}

log_failure() {
  printf "${RED}✖ %s${NORMAL}\n" "$@" >&2
}


assert_eq() {
  local expected="$1"
  local actual="$2"
  local msg="${3-}"

  if [ "$expected" == "$actual" ]; then
    return 0
  else
    [ "${#msg}" -gt 0 ] && log_failure "$expected == $actual :: $msg" || true
    return 1
  fi
}

assert_not_eq() {
  local expected="$1"
  local actual="$2"
  local msg="${3-}"

  if [ ! "$expected" == "$actual" ]; then
    return 0
  else
    [ "${#msg}" -gt 0 ] && log_failure "$expected != $actual :: $msg" || true
    return 1
  fi
}

#####################################################################

##################


program="./push_swap"
error="Error"
# the exit code of the program may conflict
valgrind_exit_error=111
total_tests=0
total_failed_tests=0

declare -A failed_tests

exec_with_input() {
	local current_test=$total_tests
	echo "TEST $current_test:"
	let total_tests++
	local test_failed=0

	local should_err="$1"
	shift 1
	local input="$@"
	local res=$($program $input)

	if [ "$should_err" -eq 0 ]; then
		assert_not_eq "$error$" "$res" "\`$program $input\` shouldn't err"
		local err_code=$?
		test_failed=$test_failed || $err_code
		if [ $err_code -eq 0 ]; then
			OS=$(uname)
			checker_res=""
			if [ "$OS" == "Linux" ]; then
				checker_res=`echo $res | ./checker_linux $input`
			elif [ "$OS" == "Darwin" ]; then
				checker_res=`echo $res | ./checker_Mac $input`
			else
    			log_failure "The operating system is not supported."
    			exit 1
			fi

			if [ checker_res != "OK" ]; then
				echo -n "    "
				log_failure "Checker failed"
				test_failed=1
			fi
		fi
	else
		assert_eq "$error" "$res" "\`$program $input\` should err"
		test_failed=$test_failed || $?
	fi

	valgrind_log_file=".valgrind-push_swap-$total_tests.log"
	valgrind --error-exitcode="$valgrind_exit_error" --leak-check=full --show-possibly-lost=yes --log-file="$valgrind_log_file" $program $input > /dev/null 2>&1
	if [ $? -eq $valgrind_exit_error ]; then
		log_failure "valgrind error for input: \`$input\`"
		if grep -q "definitely lost: [1-9][0-9]* bytes" "$valgrind_log_file" || grep -q "possibly lost: [1-9][0-9]* bytes" "$valgrind_log_file"; then
			echo -n "    "
			log_failure "memory lost"
		fi
		test_failed=1
	fi
	rm "$valgrind_log_file"
	if [ $test_failed -ne 0 ]; then
		failed_tests[$current_test]=1
		let total_failed_tests++
		echo -n "    "
		log_failure "failed"
	else
		echo -n "    "
		log_success "succeeded"
	fi
}

should_err() {
	exec_with_input 1 "$@"
}

shouldnt_err() {
	exec_with_input 0 "$@"
}

##################
# Tester #########

log_header "push_swap tester"

printf "Norminette..."
norm=`norminette`
if [ $? -ne 0 ]; then
	printf " Errors\n$YELLOW"
	echo "$norm" | grep -v 'OK!$'
	printf "$NORMAL"
else
	log_success "OK"
fi

printf "Building..."
build=`make`
if [ $? -ne 0 ]; then
	log_failure " Failed"
	printf "$build\n"
	exit 1
else
	log_success "OK"
fi


printf "Running tests...\n"

shouldnt_err 1 3 5 +9 20 -4 50 60 04 08
shouldnt_err "3 4 6 8 9 74 -56 +495"
should_err   "3 4 6 8 9 74 -56 +495 f"
should_err   1 3 dog 35 80 -3
should_err   a
should_err   1 2 3 5 67b778 947
should_err   " 12 4 6 8 54fhd 4354"
should_err   1 --    45 32
should_err   1 3 58 9 3
should_err   3 03
should_err   " 49 128     50 38   49"
shouldnt_err "95 99 -9 10 9"
shouldnt_err 2147483647 2 4 7
shouldnt_err "2147483647 843 56544 24394"
should_err   54867543867438 3
should_err   -2147483647765 4 5
should_err   "214748364748385 28 47 29"

let total_passed_tests=$total_tests-$total_failed_tests

if [ $total_tests -eq 0 ]; then
	printf "No tests\n"
elif [ $total_failed_tests -eq 0 ]; then
	log_success "All tests passed"
elif [ $total_passed_tests -eq 0 ]; then
	log_failure "All tests failed"
else
	printf "$total_passed_tests/$total_tests passed\n"
	printf "The following tests failed: "
	first=1
	for num in "${!failed_tests[@]}"; do
		if [ $first -eq 0 ]; then
			echo -n ", "
		fi
		first=0
		echo -n "$num"
	done
	echo ""
fi

make -s fclean

##################
