/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_light.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 15:12:18 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/30 16:40:09 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <liblist.h>
#include <stdlib.h>
#include <stdio.h>

void	parse_light(char **info, t_data *data)
{
	t_light	*light;

	if (char_arrlen(info) != 4)
		print_error("Wrong number of values given for light.");
	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		print_error("Malloc failed in parse_light.");
	light->pos	= parse_coord(info[1]);
	light->ratio = parse_float(info[2]);
	light->color = parse_color(info[3]);
	if (light->ratio > 1 || light->ratio < 0)
		print_error("Invalid value given for light.");
	if (!lst_new_back(&(data->lights), light))
		print_error("Allocation failed in parse_light.");
}