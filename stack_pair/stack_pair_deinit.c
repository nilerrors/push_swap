/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_deinit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:21:27 by senayat           #+#    #+#             */
/*   Updated: 2024/07/06 21:00:40 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

void	stack_pair_deinit(t_stack_pair *s)
{
	if (!s)
		return ;
	if (s->a)
		vector_destroy(s->a);
	if (s->b)
		vector_destroy(s->b);
	if (s->instructions)
		ft_lstclear(&s->instructions, NULL);
}
