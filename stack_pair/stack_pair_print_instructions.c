/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_print_instructions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:20:19 by senayat           #+#    #+#             */
/*   Updated: 2024/06/27 00:10:44 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

static void	_println(void *text)
{
	ft_putendl((char *)text);
}

void	stack_pair_print_instructions(t_stack_pair *s)
{
	if (!s || !s->instructions)
		return ;
	ft_lstiter(s->instructions, &_println);
}
