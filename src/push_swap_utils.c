/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:01:16 by senayat           #+#    #+#             */
/*   Updated: 2024/07/04 22:20:29 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_bool	push_smallest_to_b(t_stack_pair *s, int times)
{
	size_t	i;

	if (!s || !s->a || !s->b)
		return (FALSE);
	while (times > 0)
	{
		times--;
		if (!array_list_find_smallest(s->a, &i))
			return (FALSE);
		move_nth_to_top(s, i, TRUE);
		do_instructions(s, "pb");
	}
	return (TRUE);
}

static void	move_to_top_by_up(
		t_stack_pair *s, size_t index, size_t size, t_bool is_a)
{
	if (index <= size / 2)
	{
		while (index--)
		{
			if (is_a)
				do_instructions(s, "ra");
			else
				do_instructions(s, "rb");
		}
	}
}

static void	move_to_top_by_down(
		t_stack_pair *s, size_t index, size_t size, t_bool is_a)
{
	if (index > size / 2)
	{
		while (index++ < size)
		{
			if (is_a)
				do_instructions(s, "rra");
			else
				do_instructions(s, "rrb");
		}
	}
}

t_bool	move_nth_to_top(t_stack_pair *s, size_t index, t_bool is_a)
{
	size_t	size;

	size = s->b->size;
	if (is_a)
		size = s->a->size;
	if (index > size)
		return (FALSE);
	if (index == 0)
		return (TRUE);
	if (index <= size / 2)
		move_to_top_by_up(s, index, size, is_a);
	else if (index > size / 2)
		move_to_top_by_down(s, index, size, is_a);
	return (TRUE);
}
