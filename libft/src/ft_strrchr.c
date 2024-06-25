/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:24:20 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 20:11:08 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	last = (char *)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == (unsigned char)c)
			return (last + i);
		i--;
	}
	if (last[i] == (unsigned char)c)
		return (last);
	return (NULL);
}
