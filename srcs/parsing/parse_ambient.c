/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 14:42:27 by victor         #+#    #+#                */
/*   Updated: 2020/01/30 16:23:38 by vtenneke      ########   odam.nl         */
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
		print_error("Wrong number of values given for ambient lighting.");
	data->mapinfo.amb_ratio = parse_float(info[1]);
	data->mapinfo.amb_color = parse_color(info[2]);
	if (data->mapinfo.amb_ratio > 1 || data->mapinfo.amb_ratio < 0)
		print_error("Invalid value given for ambient lighting.");
}