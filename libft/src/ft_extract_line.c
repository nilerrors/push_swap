/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:34:09 by senayat           #+#    #+#             */
/*   Updated: 2024/07/11 00:02:27 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_extract_line(const char *from)
{
	char	*line;
	size_t	i;

	if (!from || !from[0])
		return (NULL);
	i = 0;
	while (from[i] && from[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	if (from[i] == '\n')
		line[i] = '\n';
	while (i > 0)
	{
		i--;
		line[i] = from[i];
	}
	return (line);
}

char	*ft_extract_line_no_endl(const char *from)
{
	char	*line;
	size_t	i;

	if (!from || !from[0])
		return (NULL);
	i = 0;
	while (from[i] && from[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (i > 0)
	{
		i--;
		line[i] = from[i];
	}
	return (line);
}
