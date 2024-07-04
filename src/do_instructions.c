/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:58:39 by senayat           #+#    #+#             */
/*   Updated: 2024/07/03 12:22:33 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static t_bool	perform_rr(t_stack_pair *s, const char *instruction)
{
	if (ft_memcmp(instruction, "rra", 3) == 0)
		stack_pair_rra(s, TRUE);
	else if (ft_memcmp(instruction, "rrb", 3) == 0)
		stack_pair_rrb(s, TRUE);
	else if (ft_memcmp(instruction, "rrr", 3) == 0)
		stack_pair_rrr(s, TRUE);
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	perform_instruction(t_stack_pair *s, const char *instruction)
{
	if (!instruction)
		return (FALSE);
	if (ft_strlen(instruction) == 3)
		return (perform_rr(s, instruction));
	if (ft_memcmp(instruction, "sa", 2) == 0)
		stack_pair_sa(s, TRUE);
	else if (ft_memcmp(instruction, "sb", 2) == 0)
		stack_pair_sb(s, TRUE);
	else if (ft_memcmp(instruction, "ss", 2) == 0)
		stack_pair_ss(s, TRUE);
	else if (ft_memcmp(instruction, "pa", 2) == 0)
		stack_pair_pa(s, TRUE);
	else if (ft_memcmp(instruction, "pb", 2) == 0)
		stack_pair_pb(s, TRUE);
	else if (ft_memcmp(instruction, "ra", 2) == 0)
		stack_pair_ra(s, TRUE);
	else if (ft_memcmp(instruction, "rb", 2) == 0)
		stack_pair_rb(s, TRUE);
	else if (ft_memcmp(instruction, "rr", 2) == 0)
		stack_pair_rr(s, TRUE);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	do_instructions(t_stack_pair *s, const char *instructions)
{
	char	**op;
	size_t	cop;

	if (!instructions || !s || !s->a || !s->b)
		return (FALSE);
	op = ft_split(instructions, ',');
	if (!op)
		return (FALSE);
	cop = 0;
	while (op[cop])
		if (!perform_instruction(s, op[cop++]))
			return (FALSE);
	ft_free_tab((void **)op);
	return (TRUE);
}
