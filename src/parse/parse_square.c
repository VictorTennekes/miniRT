/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_square.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 11:55:39 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/10 21:06:30 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Parse info into the appropriate struct and linked list.
**
**	@param	:	{char **} infos
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <liblist.h>
#include <stdlib.h>

void	parse_square(char **info, t_data *data)
{
	t_object	*object;

	if (char_arrlen(info) != 5)
		print_error("Wrong amount of values given for square", data);
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed for square", data);
	object->type = SQ;
	object->pos = parse_coord(info[1]);
	object->vector = parse_coord(info[2]);
	object->size = parse_double(info[3]);
	object->color = parse_color(info[4], data);
	if (object->vector.x > 1 || object->vector.x < -1)
		print_error("Wrong value given for square vector x", data);
	if (object->vector.y > 1 || object->vector.y < -1)
		print_error("Wrong value given for square vector y", data);
	if (object->vector.z > 1 || object->vector.z < -1)
		print_error("Wrong value given for square vector z", data);
	object->vector = vec_normalize(object->vector);
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed for square", data);	
}
