/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_pa_pb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:02:38 by senayat           #+#    #+#             */
/*   Updated: 2024/06/08 13:10:23 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

void	stack_pair_pa(t_stack_pair s, int print)
{
	int	top_b;

	if (array_list_isempty(s.b))
		return ;
	array_list_get(s.b, 0, &top_b);
	array_list_del(s.b, 0);
	array_list_insert(s.a, 0, top_b);
	if (print)
		ft_printf("pa\n");
}

void	stack_pair_pb(t_stack_pair s, int print)
{
	int	top_a;

	if (array_list_isempty(s.a))
		return ;
	array_list_get(s.a, 0, &top_a);
	array_list_del(s.a, 0);
	array_list_insert(s.b, 0, top_a);
	if (print)
		ft_printf("pb\n");
}
