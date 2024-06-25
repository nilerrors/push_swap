/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_getset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:14:24 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 20:05:24 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	array_list_set(t_array_list *list, size_t index, int new_item)
{
	if (index > list->size)
		return (0);
	list->items[index] = new_item;
	return (1);
}

int	array_list_get(t_array_list *list, size_t index, int *item)
{
	if (index > list->size)
		return (0);
	*item = list->items[index];
	return (1);
}

int	array_list_find(t_array_list *list, int item)
{
	size_t	i;
	int		n;

	i = 0;
	while (i < list->size)
	{
		if (!array_list_get(list, i, &n))
			break ;
		if (item == n)
			return (1);
		i++;
	}
	return (0);
}
