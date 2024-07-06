/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:06:48 by senayat           #+#    #+#             */
/*   Updated: 2024/07/05 23:29:11 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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
	optimize_instructions(&s.instructions);
	stack_pair_print_instructions(&s);
	stack_pair_deinit(&s);
	return (0);
}
