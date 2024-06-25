/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:06:48 by senayat           #+#    #+#             */
/*   Updated: 2024/06/24 23:28:07 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// static int	handle_input(t_stack_pair *s, argc, char **argv)
// {
//
// }

int	main(int argc, char **argv)
{
	t_stack_pair	s;
	int				should_err;

	if (argc == 1)
		return (0);
	if (argc == 2)
		should_err = !handle_single_arg(&s, argv[1]);
	else
		should_err = !validate_args(&s, argc - 1, argv + 1);
	if (should_err)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (array_list_is_sorted(s))
		ft_printf("Sorted\n");
	else
		ft_printf("Unsorted\n");
	sort_stack_pair(s);
	stack_pair_deinit(s);
	return (0);
}
