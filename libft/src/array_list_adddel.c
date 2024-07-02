/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_adddel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:15:28 by senayat           #+#    #+#             */
/*   Updated: 2024/06/26 20:41:17 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	array_list_del(t_array_list *list, size_t index)
{
	if (index > list->size)
		return (FALSE);
	while (index + 1 < list->size)
	{
		list->items[index] = list->items[(index) + 1];
		index++;
	}
	list->size--;
	return (TRUE);
}

t_bool	array_list_add(t_array_list *list, int new_item)
{
	if (list->size == list->capacity)
		if (!array_list_double_capacity(list))
			return (FALSE);
	list->items[list->size] = new_item;
	list->size++;
	return (TRUE);
}

t_bool	array_list_insert(t_array_list *list, size_t index, int new_item)
{
	size_t	i;

	if (list->size == list->capacity)
		if (!array_list_double_capacity(list))
			return (FALSE);
	i = list->size;
	while (i > index)
	{
		list->items[i] = list->items[i - 1];
		i--;
	}
	list->items[index] = new_item;
	list->size++;
	return (TRUE);
}
