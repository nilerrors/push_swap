/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:06:48 by senayat           #+#    #+#             */
/*   Updated: 2024/07/01 23:27:57 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static t_bool	handle_input(t_stack_pair *s, int argc, char **argv)
{
	int	should_err;

	if (argc == 2)
		should_err = !handle_single_arg(s, argv[1]);
	else
		should_err = !validate_args(s, argc - 1, argv + 1);
	if (should_err)
	{
		ft_printf("Error\n");
		return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_stack_pair	s;

	s.a = NULL;
	s.b = NULL;
	s.instructions = NULL;
	if (argc == 1)
		return (0);
	if (!handle_input(&s, argc, argv))
		return (1);
	sort_stack_pair(&s);
	stack_pair_print_instructions(&s);
	stack_pair_deinit(&s);
	return (0);
}
