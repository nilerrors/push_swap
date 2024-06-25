/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:59:11 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 20:11:30 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**ft_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_split_len(char const *s, char c)
{
	size_t	i;
	size_t	l;

	if (!s || !s[0])
		return (0);
	i = 0;
	l = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			l++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		l++;
	return (l);
}

static	char	*ft_nth_split_begin(char const *s, char c, size_t n)
{
	size_t	i;
	size_t	current;

	i = 0;
	current = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (current == n)
			break ;
		if (s[i] == c)
		{
			current++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i] == 0)
		return (NULL);
	return ((char *)(s + i));
}

static char	*ft_nth_split(char const *s, char c, int n)
{
	size_t	i;
	char	*temp;
	char	*str;
	size_t	size;

	temp = ft_nth_split_begin(s, c, n);
	if (!temp)
		return (NULL);
	i = 0;
	size = 0;
	while (temp[i] && temp[i] != c)
	{
		i++;
		size++;
	}
	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**tab;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_split_len(s, c);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	while (i < len)
	{
		str = ft_nth_split(s, c, i);
		if (!str)
			return (ft_malloc_error(tab));
		tab[i] = str;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
