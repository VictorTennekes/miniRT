/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pyramid.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:15:56 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:15:56 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Parse info into the appropriate struct and linked list.
**
**	@param	:	{char **} info
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <liblist.h>
#include <stdlib.h>

void	parse_pyramid(char **info, t_data *data)
{
	t_object *object;

	if (char_arrlen(info) != 6)
		print_error("Wrong amount of values given for square", data);
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed for pyramid", data);
	object->type = PY;
	object->pos[0] = parse_coord(info[1], data);
	object->vector = parse_coord(info[2], data);
	object->size = parse_double(info[3]);
	object->height = parse_double(info[4]);
	object->color = parse_color(info[5], data);
	if ((object->vector.x > 1 || object->vector.x < -1) ||
		(object->vector.y > 1 || object->vector.y < -1) ||
		(object->vector.z > 1 || object->vector.z < -1))
		print_error("Invalid orientation vector given for pyramid", data);
	object->vector = vec_normalize(object->vector);
	init_py_children(object, data);
}
