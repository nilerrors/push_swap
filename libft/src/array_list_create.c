/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:11:19 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 20:05:01 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_array_list	*array_list_create(size_t capacity)
{
	t_array_list	*arr;
	int				*items;

	arr = (t_array_list *)malloc(sizeof(t_array_list));
	if (!arr)
		return (NULL);
	arr->size = 0;
	arr->capacity = capacity;
	items = (int *)malloc(sizeof(int) * arr->capacity);
	if (!items)
	{
		free(arr);
		return (NULL);
	}
	arr->items = items;
	return (arr);
}
