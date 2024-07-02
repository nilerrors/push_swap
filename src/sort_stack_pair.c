/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_pair.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 03:27:35 by senayat           #+#    #+#             */
/*   Updated: 2024/07/02 00:01:37 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static t_bool	sort_le_three(t_stack_pair *s)
{
	int	first;
	int	second;
	int	third;

	if (!s || !s->a || !s->b)
		return (FALSE);
	if (array_list_is_sorted(s, FALSE))
		return (TRUE);
	if (s->a->size == 2)
		return (do_instructions(s, "sa"));
	array_list_get(s->a, 0, &first);
	array_list_get(s->a, 1, &second);
	array_list_get(s->a, 2, &third);
	if (first > second && second > third)
		do_instructions(s, "ra,sa");
	else if (first > second && second < third && first > third)
		do_instructions(s, "ra");
	else if (first < second && second > third && first > third)
		do_instructions(s, "rra");
	else if (first > second && second < third && first < third)
		do_instructions(s, "sa");
	else if (first < second && second > third && first < third)
		do_instructions(s, "rra,sa");
	return (TRUE);
}

static t_bool	sort_le_five(t_stack_pair *s)
{
	size_t	n;

	if (!s || !s->a || !s->b)
		return (FALSE);
	if (array_list_is_sorted(s, FALSE))
		return (TRUE);
	n = s->a->size;
	if (n <= 3)
		return (sort_le_three(s));
	push_smallest_to_b(s, n - 3);
	sort_le_three(s);
	do_instructions(s, "pa");
	if (n == 5)
		do_instructions(s, "pa");
	return (TRUE);
}

static t_bool	push_best_buddy_to_a(t_stack_pair *s)
{
	if (!s || !s->a || !s->b)
		return (FALSE);
	if (array_list_is_sorted(s, FALSE))
		return (TRUE);
	return (TRUE);
}

static t_bool	rotate_until_sorted(t_stack_pair *s)
{
	while (!array_list_is_sorted(s, FALSE))
		do_instructions(s, "ra");
	return (TRUE);
}

t_bool	sort_stack_pair(t_stack_pair *s)
{
	long	mean;
	int		n;

	if (!s || !s->a || !s->b)
		return (FALSE);
	if (array_list_is_sorted(s, FALSE))
		return (TRUE);
	if (s->a->size <= 5)
		return (sort_le_five(s));
	array_list_mean(s->a, &mean);
	while (s->a->size > 5)
	{
		array_list_get(s->a, 0, &n);
		if (n > mean)
			do_instructions(s, "ra");
		else
			(void)(do_instructions(s, "pb") && array_list_mean(s->a, &mean));
	}
	sort_le_five(s);
	while (!array_list_isempty(s->b))
		push_best_buddy_to_a(s);
	rotate_until_sorted(s);
	return (TRUE);
}
