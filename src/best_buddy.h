/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_buddy.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:11:49 by senayat           #+#    #+#             */
/*   Updated: 2024/07/04 22:25:36 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BEST_BUDDY_H
# define BEST_BUDDY_H

# include "../libft/libft.h"
# include "../stack_pair/stack_pair.h"

// bb -> best buddy
// tn -> target number
typedef struct t_best_buddy
{
	size_t	i_bb;
	size_t	i_tn;
	int		cost_bb;
	int		cost_tn;
	int		best;
	int		final_bb;
	int		final_tn;
}	t_best_buddy;

t_bool	find_best_buddy(t_stack_pair *s, size_t *index, long long n);
t_bool	push_best_buddy_to_a(t_stack_pair *s);

#endif // BEST_BUDDY_H
