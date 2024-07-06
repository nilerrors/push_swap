/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_pa_pb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:02:38 by senayat           #+#    #+#             */
/*   Updated: 2024/07/06 21:01:03 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

void	stack_pair_pa(t_stack_pair *s, t_bool print)
{
	int	top_b;

	if (vector_isempty(s->b))
		return ;
	vector_get(s->b, 0, &top_b);
	vector_del(s->b, 0);
	vector_insert(s->a, 0, top_b);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("pa"));
}

void	stack_pair_pb(t_stack_pair *s, t_bool print)
{
	int	top_a;

	if (vector_isempty(s->a))
		return ;
	vector_get(s->a, 0, &top_a);
	vector_del(s->a, 0);
	vector_insert(s->b, 0, top_a);
	if (print)
		ft_lstadd_back(&s->instructions, ft_lstnew("pb"));
}
