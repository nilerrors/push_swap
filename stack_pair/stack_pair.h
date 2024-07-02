/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:29:44 by senayat           #+#    #+#             */
/*   Updated: 2024/06/27 00:13:18 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PAIR_H
# define STACK_PAIR_H

# include "../libft/libft.h"

typedef struct t_stack_pair
{
	t_array_list	*a;
	t_array_list	*b;
	t_list			*instructions;
}	t_stack_pair;

void	stack_pair_deinit(t_stack_pair *s);
void	stack_pair_sa(t_stack_pair *s, t_bool print);
void	stack_pair_sb(t_stack_pair *s, t_bool print);
void	stack_pair_ss(t_stack_pair *s, t_bool print);
void	stack_pair_pa(t_stack_pair *s, t_bool print);
void	stack_pair_pb(t_stack_pair *s, t_bool print);
void	stack_pair_ra(t_stack_pair *s, t_bool print);
void	stack_pair_rb(t_stack_pair *s, t_bool print);
void	stack_pair_rr(t_stack_pair *s, t_bool print);
void	stack_pair_rra(t_stack_pair *s, t_bool print);
void	stack_pair_rrb(t_stack_pair *s, t_bool print);
void	stack_pair_rrr(t_stack_pair *s, t_bool print);
void	stack_pair_print_instructions(t_stack_pair *s);

#endif // STACK_PAIR_H
