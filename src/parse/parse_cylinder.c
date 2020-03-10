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

void	parse_cylinder(char **info, t_data *data)
{
	t_object	*object;

	if (char_arrlen(info) != 6)
		print_error("Invalid amount of values given for cylinder", data);
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed for cylinder", data);
	object->type = CY;
	object->pos[0] = parse_coord(info[1]);
	object->vector = parse_coord(info[2]);
	if ((object->vector.x > 1 || object->vector.x < -1) ||
		(object->vector.y > 1 || object->vector.y < -1) ||
		(object->vector.z > 1 || object->vector.z < -1))
		print_error("Invalid orientation vector given for cylinder", data);
	object->vector = vec_normalize(object->vector);
	object->size = parse_double(info[3]);
	object->height = parse_double(info[4]);
	object->color = parse_color(info[5], data);
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed for cylinder", data);
}
