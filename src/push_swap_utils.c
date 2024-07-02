/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:01:16 by senayat           #+#    #+#             */
/*   Updated: 2024/06/29 15:51:20 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_bool	handle_single_arg(t_stack_pair *s, char *str)
{
	char	**tab;
	size_t	len;
	t_bool	err;

	tab = ft_split(str, ' ');
	if (!tab)
		return (FALSE);
	len = 0;
	while (*(tab + len))
		len++;
	err = validate_args(s, len, tab);
	ft_free_tab((void **)tab);
	return (err);
}

t_bool	validate_args(t_stack_pair *s, int argc, char **argv)
{
	int	i;
	int	n;

	if (!argc || !s)
		return (FALSE);
	s->a = array_list_create(argc);
	if (!s->a)
		return (FALSE);
	s->b = array_list_create(argc);
	if (!s->b)
		return (array_list_destroy(s->a) && FALSE);
	i = 0;
	n = 0;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i++], &n) || array_list_find(s->a, n))
		{
			stack_pair_deinit(s);
			return (FALSE);
		}
		array_list_add(s->a, n);
	}
	return (TRUE);
}

t_bool	array_list_is_sorted(t_stack_pair *s, t_bool ignore_b)
{
	size_t	i;
	int		n;
	int		m;

	if (!s)
		return (FALSE);
	if (s->b->size && !ignore_b)
		return (FALSE);
	i = 1;
	while (i < s->a->size)
	{
		array_list_get(s->a, i - 1, &n);
		array_list_get(s->a, i, &m);
		if (n > m)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	push_smallest_to_b(t_stack_pair *s, int times)
{
	size_t	n;

	if (!s || !s->a || !s->b)
		return (FALSE);
	while (times > 0)
	{
		times--;
		if (!array_list_smallest(s->a, &n))
			return (FALSE);
		if (n == 0)
			continue ;
		n--;
		while (n > 0)
		{
			n--;
			do_instructions(s, "ra");
		}
		do_instructions(s, "pb");
	}
	return (TRUE);
}
