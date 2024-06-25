/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:01:16 by senayat           #+#    #+#             */
/*   Updated: 2024/06/25 00:33:07 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	handle_single_arg(t_stack_pair *s, char *str)
{
	char	**tab;
	size_t	len;
	int		any_err;

	tab = ft_split(str, ' ');
	if (!tab)
		return (0);
	len = 0;
	while (*(tab + len))
		len++;
	any_err = validate_args(s, len, tab);
	ft_free_tab((void **)tab);
	return (any_err);
}

int	validate_args(t_stack_pair *s, int argc, char **argv)
{
	int	i;
	int	n;

	s->a = array_list_create(argc);
	s->b = array_list_create(argc / 2);
	if (!argc || !s->a || !s->b)
		return (0);
	i = 0;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i++], &n) || array_list_find(s->a, n))
		{
			stack_pair_deinit(*s);
			return (0);
		}
		array_list_add(s->a, n);
	}
	return (1);
}

int	array_list_is_sorted(t_stack_pair s)
{
	size_t	i;
	int		n;
	int		m;

	if (s.b->size)
		return (0);
	i = 1;
	while (i < s.a->size)
	{
		array_list_get(s.a, i - 1, &n);
		array_list_get(s.a, i, &m);
		if (n > m)
			return (0);
		i++;
	}
	return (1);
}
