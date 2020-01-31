/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_plane.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 17:18:57 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/31 15:00:43 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <liblist.h>
#include <stdlib.h>
#include <stdio.h>

void	parse_plane(char **info, t_data *data)
{
	t_object *object;

	if (char_arrlen(info) != 4)
		print_error("Wrong value of arguments given for plane.");
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed in parse_plane.");
	object->type = PL;
	object->pos = parse_coord(info[1]);
	object->vector = parse_coord(info[2]);
	object->color = parse_color(info[3]);
	if (object->vector.x > 1 || object->vector.x < -1)
		print_error("Wrong x value for plane vector.");
	if (object->vector.y > 1 || object->vector.y < -1)
		print_error("Wrong y value for plane vector.");
	if (object->vector.z > 1 || object->vector.z < -1)
		print_error("Wrong z value for plane vector.");
	
}