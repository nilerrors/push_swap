/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_rra_rrb_rrr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:11:50 by senayat           #+#    #+#             */
/*   Updated: 2024/06/08 13:09:03 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

void	stack_pair_rra(t_stack_pair s, int print)
{
	int	bottom_a;

	if (!s.a || s.a->size < 2)
		return ;
	array_list_get(s.a, s.a->size, &bottom_a);
	array_list_del(s.a, s.a->size);
	array_list_insert(s.a, 0, bottom_a);
	if (print)
		ft_printf("rra\n");
}

void	stack_pair_rrb(t_stack_pair s, int print)
{
	int	bottom_b;

	if (!s.b || s.b->size < 2)
		return ;
	array_list_get(s.b, s.b->size, &bottom_b);
	array_list_del(s.b, s.b->size);
	array_list_insert(s.b, 0, bottom_b);
	if (print)
		ft_printf("rrb\n");
}

void	stack_pair_rrr(t_stack_pair s, int print)
{
	stack_pair_rra(s, 0);
	stack_pair_rrb(s, 0);
	if (print)
		ft_printf("rrr\n");
}
