/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair_init_deinit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:21:27 by senayat           #+#    #+#             */
/*   Updated: 2024/06/09 15:25:13 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_pair.h"

void	stack_pair_deinit(t_stack_pair s)
{
	array_list_destroy(s.a);
	array_list_destroy(s.b);
}
