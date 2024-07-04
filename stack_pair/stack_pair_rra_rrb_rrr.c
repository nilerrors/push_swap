/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_rra_rrb_rrr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:11:50 by senayat           #+#    #+#             */
/*   Updated: 2024/07/04 11:51:19 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

void	stack_pair_rra(t_stack_pair *s, t_bool print)
{
	int	bottom_a;

	if (!s->a || s->a->size < 2)
		return ;
	array_list_get(s->a, s->a->size - 1, &bottom_a);
	array_list_del(s->a, s->a->size - 1);
	array_list_insert(s->a, 0, bottom_a);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("rra"));
}

void	stack_pair_rrb(t_stack_pair *s, t_bool print)
{
	int	bottom_b;

	if (!s->b || s->b->size < 2)
		return ;
	array_list_get(s->b, s->b->size - 1, &bottom_b);
	array_list_del(s->b, s->b->size - 1);
	array_list_insert(s->b, 0, bottom_b);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("rrb"));
}

void	stack_pair_rrr(t_stack_pair *s, t_bool print)
{
	stack_pair_rra(s, FALSE);
	stack_pair_rrb(s, FALSE);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("rrr"));
}
