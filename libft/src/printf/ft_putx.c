/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:01:00 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 23:57:27 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_putx(unsigned int n, char f)
{
	char			*base;
	unsigned int	num;
	size_t			i;

	if (f == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	num = n;
	if (num > 15)
		i += ft_putx(num / 16, f);
	i += ft_putc(base[num % 16]);
	return (i);
}
