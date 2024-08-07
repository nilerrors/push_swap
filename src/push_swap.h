/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:29:43 by senayat           #+#    #+#             */
/*   Updated: 2024/07/05 23:30:00 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../stack_pair/stack_pair.h"

t_bool	handle_input(t_stack_pair *s, int argc, char **argv);
t_bool	handle_single_arg(t_stack_pair *s, char *str);
t_bool	validate_args(t_stack_pair *s, int argc, char **argv);
t_bool	push_smallest_to_b(t_stack_pair *s, int times);
t_bool	move_nth_to_top(t_stack_pair *s, size_t index, t_bool is_a);
t_bool	do_instructions(t_stack_pair *s, const char *instructions);
t_bool	sort_stack_pair(t_stack_pair *s);
t_bool	optimize_instructions(t_list **instructions);

#endif // PUSH_SWAP_H
