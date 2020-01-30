/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 12:24:50 by victor         #+#    #+#                */
/*   Updated: 2020/01/30 12:26:37 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minirt.h>

#include <stdio.h>
#include <errno.h>

int		isdigit_str(char *str)
{
	if (!str)
		print_error("Invalid value.");
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}