/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_float.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 14:53:33 by victor         #+#    #+#                */
/*   Updated: 2020/01/28 15:47:48 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>

#include <errno.h>
#include <stdio.h>

float	parse_float(char *str)
{
	int		pow_len;
	char	**numbers;
	float	res;

	numbers = ft_split(str, '.');
	pow_len = ft_strlen(numbers[1]);
	res = ft_atoi(numbers[1]);
	res /= pow(10, pow_len);
	res += ft_atoi(numbers[0]);
	free (numbers);
	printf("res: %f\n", res);
	return (res);
}