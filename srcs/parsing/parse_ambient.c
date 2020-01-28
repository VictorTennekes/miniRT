/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 14:42:27 by victor         #+#    #+#                */
/*   Updated: 2020/01/28 15:15:00 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>

#include <stdio.h>

void	parse_ambient(char **info, t_data *data)
{
	if (data->mapinfo.amb_set == true)
		print_error("Multiple ambient lighting specifications.");
	if (char_arrlen(info) != 3)
		print_error("Wrong number of values given for ambient lghting.");
	data->mapinfo.amb_ratio = parse_float(info[1]);
	printf("ratio:%f", data->mapinfo.amb_ratio);
}