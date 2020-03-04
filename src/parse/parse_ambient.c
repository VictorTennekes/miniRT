/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 14:42:27 by victor         #+#    #+#                */
/*   Updated: 2020/02/07 14:31:24 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>

#include <stdio.h>

void	parse_ambient(char **info, t_data *data)
{
	if (data->mapinfo.amb_set == true)
		print_error("Ambient light can only be specified once", data);
	if (char_arrlen(info) != 3)
		print_error("Invalid amount of values given for ambient lighting", data);
	data->mapinfo.amb_ratio = parse_double(info[1]);
	data->mapinfo.amb_color = parse_color(info[2], data);
	if (data->mapinfo.amb_ratio > 1 || data->mapinfo.amb_ratio < 0)
		print_error("Invalid value given for ambient light", data);
	data->mapinfo.amb_set = true;
}