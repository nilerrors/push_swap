/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:00:55 by senayat           #+#    #+#             */
/*   Updated: 2024/07/04 22:01:44 by senayat          ###   ########.fr       */
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
		if (!ft_isinteger(argv[i++], &n) || array_list_find(s->a, n, NULL))
		{
			stack_pair_deinit(s);
			return (FALSE);
		}
		array_list_add(s->a, n);
	}
	return (TRUE);
}
