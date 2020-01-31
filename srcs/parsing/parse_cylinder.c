/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cylinder.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 14:40:06 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/31 15:25:53 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <stdlib.h>
#include <liblist.h>

#include <stdio.h>

void	parse_cylinder(char **info, t_data *data)
{
	t_object *object;

	if (char_arrlen(info) != 6)
		print_error("Wrong value of arguments fiven for cylinder");
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed in parse_cylinder");
	object->type = CY;
	object->pos = parse_coord(info[1]);
	object->vector = parse_coord(info[2]);
	object->size = parse_float(info[3]);
	object->height = parse_float(info[4]);
	object->color = parse_color(info[5]);
	if (object->vector.x > 1 || object->vector.x < -1)
		print_error("Wrong x value for cylinder vector.");
	if (object->vector.y > 1 || object->vector.y < -1)
		print_error("Wrong y value for cylinder vector.");
	if (object->vector.z > 1 || object->vector.z < -1)
		print_error("Wrong z value for cylinder vector.");
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed in parse_cylinder");	
}