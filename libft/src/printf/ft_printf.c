/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:04:52 by senayat           #+#    #+#             */
/*   Updated: 2024/06/05 23:54:39 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "../../libft.h"

static void	ft_putfmt(va_list *args, char f, size_t *n)
{
	if (f == '%')
		*n += ft_putc('%');
	else if (f == 'c')
		*n += ft_putc(va_arg(*args, int));
	else if (f == 's')
		*n += ft_puts(va_arg(*args, char *));
	else if (f == 'p')
		*n += ft_putp(va_arg(*args, void *));
	else if (f == 'd' || f == 'i')
		*n += ft_putd(va_arg(*args, int));
	else if (f == 'u')
		*n += ft_putu(va_arg(*args, unsigned int));
	else if (f == 'x' || f == 'X')
		*n += ft_putx(va_arg(*args, unsigned int), f);
	else
		(*n)--;
}

static void	ft_fmt(va_list *args, const char *s, size_t *n)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_putfmt(args, s[i], n);
		}
		else
			*n += ft_putc(s[i]);
		i++;
	}
}

int	ft_printf(const char *s, ...)
{
	size_t	n;
	va_list	args;

	n = 0;
	va_start(args, s);
	ft_fmt(&args, s, &n);
	va_end(args);
	return (n);
}
