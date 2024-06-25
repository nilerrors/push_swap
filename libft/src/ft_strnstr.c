/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:06:16 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 20:11:08 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_str_startswith(const char *s, const char *w, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && w[i] && i < n)
	{
		if (s[i] != w[i])
			return (0);
		i++;
	}
	return (w[i] == '\0');
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (ft_str_startswith(haystack + i, needle, len - i))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
