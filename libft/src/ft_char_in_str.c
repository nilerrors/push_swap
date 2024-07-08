/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:42:39 by senayat           #+#    #+#             */
/*   Updated: 2024/07/08 23:42:42 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_char_in_str(char c, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (TRUE);
	return (FALSE);
}
