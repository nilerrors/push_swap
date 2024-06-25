/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:58:36 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 20:11:08 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nbrlen(long int nbr)
{
	size_t	len;

	len = (nbr <= 0);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_neg2147483648(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_itoa_neg2147483648());
	negative = (n < 0);
	len = ft_nbrlen(n);
	if (n < 0)
		n = -n;
	if (n < 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
