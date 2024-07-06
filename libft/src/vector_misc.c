/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:12:59 by senayat           #+#    #+#             */
/*   Updated: 2024/07/06 20:56:06 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	vector_clear(t_vector *list)
{
	list->size = 0;
	return (TRUE);
}

t_bool	vector_destroy(t_vector *list)
{
	free(list->items);
	free(list);
	return (TRUE);
}

t_bool	vector_isempty(t_vector *list)
{
	return (list->size == 0);
}

t_bool	vector_double_capacity(t_vector *list)
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
