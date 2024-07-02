/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:34:34 by senayat           #+#    #+#             */
/*   Updated: 2024/07/01 23:59:29 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	array_list_smallest(t_array_list *list, size_t *index)
{
	int		n;
	int		smallest;

	if (!list || array_list_isempty(list))
		return (FALSE);
	*index = 1;
	array_list_get(list, 0, &n);
	smallest = n;
	while (*index < list->size)
	{
		array_list_get(list, (*index)++, &n);
		if (smallest > n)
		{
			smallest = n;
		}
	}
	return (TRUE);
}

t_bool	array_list_mean(t_array_list *list, long *mean)
{
	size_t	i;
	int		n;
	long	sum;

	if (!list || !list->size)
		return (FALSE);
	i = 0;
	n = 0;
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
