/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:26:58 by vtenneke      #+#    #+#                 */
/*   Updated: 2019/12/04 13:01:34 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static long int		ft_edge(const char *str, unsigned long int res, int sign)
{
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
		if (res > 9223372036854775807UL && sign == 1)
			return (-1);
		else if (res > 9223372036854775808UL && sign == -1)
			return (0);
	}
	return (res);
}

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = *str == '-' ? -1 : 1;
		str++;
	}
	res = ft_edge(str, res, sign);
	return (sign * (int)res);
}
