/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:47:17 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 20:11:46 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (ft_strlen(s) < start)
		ft_strlcpy(str, "", 1);
	else
		ft_strlcpy(str, s + start, len + 1);
	return (str);
}
