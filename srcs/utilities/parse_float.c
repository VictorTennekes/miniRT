/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_float.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 14:53:33 by victor         #+#    #+#                */
/*   Updated: 2020/02/03 11:23:44 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <math.h>
#include <stdlib.h>


float	parse_float(char *str)
{
	float	res;
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
