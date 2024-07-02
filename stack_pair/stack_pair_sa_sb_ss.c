/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_sa_sb_ss.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:41:31 by senayat           #+#    #+#             */
/*   Updated: 2024/06/27 14:28:33 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

void	stack_pair_sa(t_stack_pair *s, t_bool print)
{
	int	top;
	int	below_top;

	if (!s->a || s->a->size < 2)
		return ;
	array_list_get(s->a, 0, &top);
	array_list_get(s->a, 1, &below_top);
	array_list_set(s->a, 0, below_top);
	array_list_set(s->a, 1, top);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("sa"));
}

void	stack_pair_sb(t_stack_pair *s, t_bool print)
{
	int	top;
	int	below_top;

	if (!s->b || s->b->size < 2)
		return ;
	array_list_get(s->b, 0, &top);
	array_list_get(s->b, 1, &below_top);
	array_list_set(s->b, 0, below_top);
	array_list_set(s->b, 1, top);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("sb"));
}

void	stack_pair_ss(t_stack_pair *s, t_bool print)
{
	stack_pair_sa(s, FALSE);
	stack_pair_sb(s, FALSE);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("ss"));
}
