/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_is_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:19:07 by senayat           #+#    #+#             */
/*   Updated: 2024/07/04 22:19:10 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

t_bool	stack_pair_is_sorted(t_stack_pair *s, t_bool ignore_b)
{
	size_t	i;
	int		n;
	int		m;

	if (!s)
		return (FALSE);
	if (s->b->size && !ignore_b)
		return (FALSE);
	i = 1;
	while (i < s->a->size)
	{
		array_list_get(s->a, i - 1, &n);
		array_list_get(s->a, i, &m);
		if (n > m)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
