/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:00:55 by senayat           #+#    #+#             */
/*   Updated: 2024/07/06 20:58:17 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_bool	handle_input(t_stack_pair *s, int argc, char **argv)
{
	int	should_err;

	if (argc == 2)
		should_err = !handle_single_arg(s, argv[1]);
	else
		should_err = !validate_args(s, argc - 1, argv + 1);
	if (should_err)
	{
		ft_printf("Error\n");
		return (FALSE);
	}
	return (TRUE);
}

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
	s->a = vector_create(argc);
	if (!s->a)
		return (FALSE);
	s->b = vector_create(argc);
	if (!s->b)
		return (vector_destroy(s->a) && FALSE);
	i = 0;
	n = 0;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i++], &n) || vector_find(s->a, n, NULL))
		{
			stack_pair_deinit(s);
			return (FALSE);
		}
		vector_add(s->a, n);
	}
	return (TRUE);
}
