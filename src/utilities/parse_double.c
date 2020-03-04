/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_double.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 13:29:28 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/06 13:29:29 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>
#include <stdlib.h>


double	parse_double(char *str)
{
	double	res;
	int		count;
	bool	is_neg;

	res = ft_atoi(str);
	is_neg = false;
	if (res < 0 || *str == '-')
	{
		str++;
		is_neg = true;
	}
	while (ft_isdigit(*str))
		str++;
	count = 1;
	if (*str != '.')
		return (res);
	str++;
	while (ft_isdigit(*str))
	{
		res += (((int)(*str - '0')) / pow(10, count) * (is_neg ? -1 : 1));
		count++;
		str++;
	}
	return(res);
}
