/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: senayat <senayat@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/23 18:04:49 by senayat		   #+#	#+#			 */
/*   Updated: 2024/06/24 12:06:31 by senayat          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../libft.h"

static int	int_overflows(long long n)
{
	return ((n > INT_MAX) || (n < INT_MIN));
}

static void	skip_space(const char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static int	handle_current_dig(const char *str, long long *res, int isneg)
{
	int	dig;

	dig = (*str - '0');
	if ((isneg && (-*res < (LLONG_MIN + dig) / 10))
		|| (!isneg && (*res > (LLONG_MAX - dig) / 10)))
		return (0);
	*res = (*res) * 10 + dig;
	return (1);
}

int	ft_isinteger(const char *str, int *n)
{
	int			isneg;
	long long	res;

	isneg = 0;
	res = 0;
	if (!str || *str == '\0')
		return (0);
	skip_space(&str);
	if (*str == '+' || *str == '-')
		isneg = (*(str++) == '-');
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		if (!handle_current_dig(str++, &res, isneg))
			return (0);
	skip_space(&str);
	if (isneg)
		res = -res;
	if (*str != '\0' || int_overflows(res))
		return (0);
	if (n)
		*n = (int)res;
	return (1);
}
