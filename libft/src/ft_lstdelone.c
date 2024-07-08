/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:04:39 by senayat           #+#    #+#             */
/*   Updated: 2024/07/08 23:44:39 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}

void	ft_lstremove(t_list **lst, t_list *node, void (*del)(void *))
{
	t_list	*current;
	t_list	*prev;

	if (!lst || !*lst || !node)
		return ;
	current = *lst;
	prev = NULL;
	while (current && current != node)
	{
		prev = current;
		current = current->next;
	}
	if (current == node)
	{
		if (prev)
			prev->next = current->next;
		else
			*lst = current->next;
		ft_lstdelone(current, del);
	}
}
