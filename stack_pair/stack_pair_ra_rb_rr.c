/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_ra_rb_rr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:07:32 by senayat           #+#    #+#             */
/*   Updated: 2024/06/08 13:09:56 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

void	stack_pair_ra(t_stack_pair s, int print)
{
	int	top_a;

	if (!s.a || s.a->size < 2)
		return ;
	array_list_get(s.a, 0, &top_a);
	array_list_del(s.a, 0);
	array_list_add(s.a, top_a);
	if (print)
		ft_printf("ra\n");
}

void	stack_pair_rb(t_stack_pair s, int print)
{
	int	top_b;

	if (!s.b || s.b->size < 2)
		return ;
	array_list_get(s.b, 0, &top_b);
	array_list_del(s.b, 0);
	array_list_add(s.b, top_b);
	if (print)
		ft_printf("rb\n");
}

void	stack_pair_rr(t_stack_pair s, int print)
{
	stack_pair_ra(s, 0);
	stack_pair_rb(s, 0);
	if (print)
		ft_printf("rr\n");
}
