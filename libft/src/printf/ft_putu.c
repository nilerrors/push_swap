/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:05:03 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 23:57:17 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_putu(unsigned int n)
{
	size_t	len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (n > 9)
		len += ft_putu(n / 10);
	len += ft_putc(base[n % 10]);
	return (len);
}
