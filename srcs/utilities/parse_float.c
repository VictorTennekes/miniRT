/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_float.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 14:53:33 by victor         #+#    #+#                */
/*   Updated: 2020/01/28 15:26:44 by victor        ########   odam.nl         */
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
	// printf("no1: %s\nno: %s\n", numbers[0], numbers[1]);
	pow_len = ft_strlen(numbers[1]);
	// printf("pow_len:%i", pow_len);
	res = ft_atoi(numbers[0]);
	res *= pow(10, pow_len);
	// printf("res: %f\n", res);
	res += ft_atoi(numbers[2]);
	res /= pow(10, pow_len);
	printf("res: %f\n", res);
	return (res);

}