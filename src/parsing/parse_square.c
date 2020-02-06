/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_square.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 11:55:39 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/06 14:14:04 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <stdlib.h>
#include <liblist.h>

void	parse_square(char **info, t_data *data)
{
	t_object	*object;

	if (char_arrlen(info) != 5)
		print_error("Wrong amount of values given for square");
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed for square");
	object->type = SQ;
	object->pos = parse_coord(info[1]);
	object->vector = parse_coord(info[2]);
	object->size = parse_double(info[3]);
	object->color = parse_color(info[4]);
	object->pos = normalize_coords(object->pos, data);
	object->vector = normalize_vector(object->vector);
	if (object->vector.x > 1 || object->vector.x < -1)
		print_error("Wrong value given for square vector x");
	if (object->vector.y > 1 || object->vector.y < -1)
		print_error("Wrong value given for square vector y");
	if (object->vector.z > 1 || object->vector.z < -1)
		print_error("Wrong value given for square vector z");
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed for square");	
}
