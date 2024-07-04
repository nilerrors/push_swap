/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:34:34 by senayat           #+#    #+#             */
/*   Updated: 2024/07/04 10:56:15 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	array_list_mean(t_array_list *list, long *mean)
{
	size_t	i;
	int		n;
	long	sum;

	if (!list || !list->size)
		return (FALSE);
	i = 0;
	sum = 0;
	while (i < list->size)
	{
		array_list_get(list, i, &n);
		sum += n;
		i++;
	}
	*mean = sum / (long)list->size;
	return (TRUE);
}

t_bool	array_list_find_smallest(t_array_list *list, size_t *index)
{
	size_t	i;
	int		n;
	int		cur;

	if (!list || !list->size)
		return (FALSE);
	i = 1;
	array_list_get(list, 0, &n);
	while (i < list->size)
	{
		array_list_get(list, i, &cur);
		if (cur < n)
			n = cur;
		i++;
	}
	array_list_find(list, n, index);
	return (TRUE);
}

int	array_list_cost_move_to_top(size_t size, size_t index)
{
	if (index <= size / 2)
		return (index);
	else if (index > size / 2)
		return (size - index);
	return (0);
}
