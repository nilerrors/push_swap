/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 23:30:27 by senayat           #+#    #+#             */
/*   Updated: 2024/07/06 14:23:04 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static t_bool	should_remove_instructions(t_list *current, t_list *next)
{
	return ((ft_strncmp(current->content, "pa", 2) == 0
			&& ft_strncmp(next->content, "pb", 2) == 0)
		|| (ft_strncmp(current->content, "pb", 2) == 0
			&& ft_strncmp(next->content, "pa", 2) == 0)
		|| (ft_strncmp(current->content, "ra", 2) == 0
			&& ft_strncmp(next->content, "rra", 3) == 0)
		|| (ft_strncmp(current->content, "rra", 3) == 0
			&& ft_strncmp(next->content, "ra", 2) == 0)
		|| (ft_strncmp(current->content, "rb", 2) == 0
			&& ft_strncmp(next->content, "rrb", 3) == 0)
		|| (ft_strncmp(current->content, "rrb", 3) == 0
			&& ft_strncmp(next->content, "rb", 2) == 0)
		|| (ft_strncmp(current->content, "sa", 2) == 0
			&& ft_strncmp(next->content, "sa", 2) == 0)
		|| (ft_strncmp(current->content, "sb", 2) == 0
			&& ft_strncmp(next->content, "sb", 2) == 0)
		|| (ft_strncmp(current->content, "ss", 2) == 0
			&& ft_strncmp(next->content, "ss", 2) == 0)
		|| (ft_strncmp(current->content, "rr", 2) == 0
			&& ft_strncmp(next->content, "rrr", 3) == 0)
		|| (ft_strncmp(current->content, "rrr", 3) == 0
			&& ft_strncmp(next->content, "rr", 2) == 0));
}

t_bool	optimize_instructions(t_list **instructions)
{
	t_list	*current;
	t_list	*next;
	t_list	*tmp;

	if (!instructions)
		return (FALSE);
	current = *instructions;
	while (current && current->next)
	{
		next = current->next;
		if (!should_remove_instructions(current, next))
			current = current->next;
		else
		{
			ft_lstremove(instructions, next, NULL);
			tmp = current->next;
			ft_lstremove(instructions, current, NULL);
			if (tmp)
				current = tmp;
			else
				current = *instructions;
		}
	}
	return (TRUE);
}
