/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_ra_rb_rr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:07:32 by senayat           #+#    #+#             */
/*   Updated: 2024/06/27 14:39:24 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

void	stack_pair_ra(t_stack_pair *s, t_bool print)
{
	int	top_a;

	if (!s->a || s->a->size < 2)
		return ;
	array_list_get(s->a, 0, &top_a);
	array_list_del(s->a, 0);
	array_list_add(s->a, top_a);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("ra"));
}

void	stack_pair_rb(t_stack_pair *s, t_bool print)
{
	int	top_b;

	if (!s->b || s->b->size < 2)
		return ;
	array_list_get(s->b, 0, &top_b);
	array_list_del(s->b, 0);
	array_list_add(s->b, top_b);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("rb"));
}

void	stack_pair_rr(t_stack_pair *s, t_bool print)
{
	stack_pair_ra(s, FALSE);
	stack_pair_rb(s, FALSE);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("rr"));
}
