/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_buddy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:15:05 by senayat           #+#    #+#             */
/*   Updated: 2024/07/04 22:41:45 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./best_buddy.h"
#include "./push_swap.h"

static void	best_buddy_init(t_best_buddy *bb)
{
	if (!bb)
		return ;
	bb->best = INT_MAX;
	bb->i_bb = 0;
	bb->i_tn = 0;
	bb->cost_bb = 0;
	bb->cost_tn = 0;
	bb->final_bb = 0;
	bb->final_tn = 0;
}

t_bool	find_best_buddy(t_stack_pair *s, size_t *index, long long n)
{
	long long	bb;
	long long	min_diff;
	int			cur_n;
	size_t		i;

	if (!s || !s->a || !s->b || !index)
		return (FALSE);
	i = 0;
	bb = LLONG_MAX;
	min_diff = LLONG_MAX;
	while (i < s->a->size)
	{
		array_list_get(s->a, i, &cur_n);
		if (cur_n > n && min_diff > cur_n - n)
		{
			min_diff = cur_n - n;
			bb = cur_n;
		}
		i++;
	}
	if (bb == LLONG_MAX)
		return (FALSE);
	array_list_find(s->a, bb, index);
	return (TRUE);
}

static void	update_best_buddy(t_stack_pair *s, t_best_buddy *bb)
{
	if (!s || !bb)
		return ;
	bb->cost_bb = array_list_cost_move_to_top(s->a->size, bb->i_bb);
	bb->cost_tn = array_list_cost_move_to_top(s->b->size, bb->i_tn);
	if (bb->cost_bb + bb->cost_tn < bb->best && bb->cost_bb + bb->cost_tn >= 0)
	{
		bb->final_bb = bb->i_bb;
		bb->final_tn = bb->i_tn;
		bb->best = bb->cost_bb + bb->cost_tn;
	}
}

t_bool	push_best_buddy_to_a(t_stack_pair *s)
{
	size_t			i;
	int				cur_n;
	t_best_buddy	bb;

	if (!s || !s->a || !s->b)
		return (FALSE);
	if (stack_pair_is_sorted(s, FALSE))
		return (TRUE);
	i = 0;
	best_buddy_init(&bb);
	while (i < s->b->size)
	{
		array_list_get(s->b, i, &cur_n);
		if (find_best_buddy(s, &bb.i_bb, cur_n))
			update_best_buddy(s, &bb);
		i++;
		bb.i_tn++;
	}
	move_nth_to_top(s, bb.final_bb, TRUE);
	move_nth_to_top(s, bb.final_tn, FALSE);
	do_instructions(s, "pa");
	return (TRUE);
}
