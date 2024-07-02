/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:23:19 by senayat           #+#    #+#             */
/*   Updated: 2024/06/26 23:58:20 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_bool	int_overflows(long long n)
{
	return ((n > INT_MAX) || (n < INT_MIN));
}

static void	skip_space(const char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static t_bool
	handle_current_dig(const char *str, long long *res, t_bool isneg)
{
	int	dig;

	dig = (*str - '0');
	if ((isneg && (-*res < (LLONG_MIN + dig) / 10))
		|| (!isneg && (*res > (LLONG_MAX - dig) / 10)))
		return (FALSE);
	*res = (*res) * 10 + dig;
	return (TRUE);
}

t_bool	ft_isinteger(const char *str, int *n)
{
	t_bool		isneg;
	long long	res;

	isneg = FALSE;
	res = 0;
	if (!str || *str == '\0')
		return (FALSE);
	skip_space(&str);
	if (*str == '+' || *str == '-')
		isneg = (*(str++) == '-');
	if (!ft_isdigit(*str))
		return (FALSE);
	while (ft_isdigit(*str))
		if (!handle_current_dig(str++, &res, isneg))
			return (FALSE);
	skip_space(&str);
	if (isneg)
		res = -res;
	if (*str != '\0' || int_overflows(res))
		return (FALSE);
	if (n)
		*n = (int)res;
	return (TRUE);
}
