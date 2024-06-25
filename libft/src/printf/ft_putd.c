/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:55:05 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 23:55:04 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_putd(int nbr)
{
	char	*base;
	long	nb;
	char	c;
	size_t	n;

	n = 1;
	base = "0123456789";
	if (nbr < 0)
	{
		n++;
		write(1, "-", 1);
		nb = - (long)nbr;
	}
	else
		nb = (long)nbr;
	if (nb > 9)
	{
		n += ft_putd(nb / 10);
	}
	c = base[nb % 10];
	write(1, &c, 1);
	return (n);
}
