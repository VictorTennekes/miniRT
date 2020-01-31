/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_float.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 14:53:33 by victor         #+#    #+#                */
/*   Updated: 2020/01/31 10:55:50 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>
#include <minirt.h>

#include <stdlib.h>

#include <errno.h>
#include <stdio.h>

float	parse_float(char *str)
{
	int		pow_len;
	char	**numbers;
	char	*if_minus;
	int		sign;
	float	res;

	sign = 1;
	numbers = ft_split(str, '.');
	if (!ft_strncmp(&numbers[0][0], "-", 1))
	{
		sign = -1;
		if_minus = ft_strtrim(numbers[0], "-");
		numbers[0] = if_minus;
	}
	if (char_arrlen(numbers) != 2)
	{
		if (!isdigit_str(numbers[0]))
			print_error("Invalid value specified");
		res = ft_atoi(numbers[0]);
		free_machine(numbers);
		return (res * sign);
	}
	if (!isdigit_str(numbers[0]) || !isdigit_str(numbers[1]))
	print_error("Invalid value specified.");
	pow_len = ft_strlen(numbers[1]);
	res = ft_atoi(numbers[1]);
	res /= pow(10, pow_len);
	res += ft_atoi(numbers[0]);
	free_machine(numbers);
	return (res * sign);
}