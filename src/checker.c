/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:50:27 by senayat           #+#    #+#             */
/*   Updated: 2024/07/11 00:10:03 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_bool	read_handle_commands(t_stack_pair *s)
{
	char	*ln;
	char	*op;

	ln = get_next_line(FD_STDIN);
	while (ln)
	{
		op = ft_extract_line_no_endl(ln);
		if (!op)
			return (FALSE);
		free(ln);
		if (!do_instructions(s, op))
			return (FALSE);
		ln = get_next_line(FD_STDIN);
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_stack_pair	s;
	t_bool			err;

	s.a = NULL;
	s.b = NULL;
	s.instructions = NULL;
	err = FALSE;
	if (argc == 1)
		return (0);

	err = !handle_input(&s, argc, argv);
	if (err)
		return (1);
	err = !read_handle_commands(&s);
	if (err)
		ft_putendl("Error");
	if (stack_pair_is_sorted(&s, FALSE))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	stack_pair_deinit(&s);
	return (0);
}
