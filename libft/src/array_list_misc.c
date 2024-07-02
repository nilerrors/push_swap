/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_misc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:12:59 by senayat           #+#    #+#             */
/*   Updated: 2024/06/26 20:46:03 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	array_list_clear(t_array_list *list)
{
	list->size = 0;
	return (TRUE);
}

t_bool	array_list_destroy(t_array_list *list)
{
	free(list->items);
	free(list);
	return (TRUE);
}

t_bool	array_list_isempty(t_array_list *list)
{
	return (list->size == 0);
}

t_bool	array_list_double_capacity(t_array_list *list)
{
	size_t	i;
	int		*items;

	items = (int *)malloc(sizeof(int) * list->size);
	if (!items)
		return (FALSE);
	i = 0;
	while (i < list->size)
	{
		items[i] = list->items[i];
		i++;
	}
	free(list->items);
	list->capacity *= 2;
	list->items = (int *)malloc(sizeof(int) * list->capacity);
	if (!list->items)
		return (ft_set_free((void **)&items) && FALSE);
	i = 0;
	while (i < list->size)
	{
		list->items[i] = items[i];
		i++;
	}
	free(items);
	return (TRUE);
}
