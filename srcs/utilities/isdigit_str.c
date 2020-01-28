/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 12:24:50 by victor         #+#    #+#                */
/*   Updated: 2020/01/28 12:55:01 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>

int		isdigit_str(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}