/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cylinder.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 14:40:06 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/10 21:06:30 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <stdlib.h>
#include <liblist.h>

#include <stdio.h>

void	parse_cylinder(char **info, t_data *data)
{
	t_object	*object;

	if (char_arrlen(info) != 6)
		print_error("Wrong amount of values given for cylinder", data);
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed for cylinder", data);
	object->type = CY;
	object->pos = parse_coord(info[1]);
	object->vector = parse_coord(info[2]);
	object->size = parse_double(info[3]);
	object->height = parse_double(info[4]);
	object->color = parse_color(info[5], data);
	if (object->vector.x > 1 || object->vector.x < -1)
		print_error("Wrong value given for cylinder vector x", data);
	if (object->vector.y > 1 || object->vector.y < -1)
		print_error("Wrong value given for cylinder vector y", data);
	if (object->vector.z > 1 || object->vector.z < -1)
		print_error("Wrong value given for cylinder vector z", data);
	object->vector = vec_normalize(object->vector);
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed for cylinder", data);	
}
