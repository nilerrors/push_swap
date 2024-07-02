/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_getset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:14:24 by senayat           #+#    #+#             */
/*   Updated: 2024/06/26 10:20:27 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	array_list_set(t_array_list *list, size_t index, int new_item)
{
	if (index > list->size)
		return (FALSE);
	list->items[index] = new_item;
	return (TRUE);
}

t_bool	array_list_get(t_array_list *list, size_t index, int *item)
{
	if (index > list->size)
		return (FALSE);
	*item = list->items[index];
	return (TRUE);
}

t_bool	array_list_find(t_array_list *list, int item)
{
	size_t	i;
	int		n;

	i = 0;
	while (i < list->size)
	{
		if (!array_list_get(list, i, &n))
			break ;
		if (item == n)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
