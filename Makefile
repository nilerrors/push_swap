# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: senayat <senayat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 22:45:48 by senayat           #+#    #+#              #
#    Updated: 2024/07/06 13:26:03 by senayat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	./src/push_swap.c									\
				./src/push_swap_utils.c								\
				./src/sort_stack_pair.c								\
				./src/best_buddy.c									\
				./src/handle_args.c									\
				./src/optimize_instructions.c						\
				./src/do_instructions.c								\
				./stack_pair/stack_pair_deinit.c					\
				./stack_pair/stack_pair_print_instructions.c		\
				./stack_pair/stack_pair_is_sorted.c					\
				./stack_pair/stack_pair_pa_pb.c						\
				./stack_pair/stack_pair_ra_rb_rr.c					\
				./stack_pair/stack_pair_rra_rrb_rrr.c				\
				./stack_pair/stack_pair_sa_sb_ss.c

OBJS		=	$(SRCS:.c=.o)

LIB			=	./libft/libft.a

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Wuninitialized -Werror -fanalyzer -I.

NAME		=	push_swap

all:		$(NAME)

lib:
			@$(MAKE) lib -C ./libft

$(NAME):	$(OBJS) lib
			@${CC} ${CFLAGS} ${OBJS} $(LIB) -o ${NAME}

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(MAKE) fclean -C ./libft
			@$(RM) $(NAME)

re:			fclean	all

.PHONY:		all	clean	fclean	re
