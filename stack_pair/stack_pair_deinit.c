/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_deinit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:21:27 by senayat           #+#    #+#             */
/*   Updated: 2024/06/27 00:20:04 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

void	stack_pair_deinit(t_stack_pair *s)
{
	if (!s)
		return ;
	if (s->a)
		array_list_destroy(s->a);
	if (s->b)
		array_list_destroy(s->b);
	if (s->instructions)
		ft_lstclear(&s->instructions, NULL);
}
