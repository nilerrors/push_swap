/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:29:43 by senayat           #+#    #+#             */
/*   Updated: 2024/06/24 10:56:10 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../stack_pair/stack_pair.h"

int	handle_single_arg(t_stack_pair *s, char *str);
int	validate_args(t_stack_pair *s, int argc, char **argv);
int	array_list_is_sorted(t_stack_pair s);
int	sort_stack_pair(t_stack_pair s);

#endif // PUSH_SWAP_H
