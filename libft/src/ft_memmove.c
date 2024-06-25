/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:56:15 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 20:10:59 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	*ft_cpylr(void *dst, const void *src, size_t len)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		*(unsigned char *)(dst + i)
			= *(unsigned char *)(src + i);
		i--;
	}
	return (dst);
}

static void	*ft_cpyrl(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(dst + i)
			= *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src && dst - src < (int)len)
		return (ft_cpylr(dst, src, len));
	if (src > dst && src - dst < (int)len)
		return (ft_cpyrl(dst, src, len));
	ft_memcpy(dst, src, len);
	return (dst);
}
