/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_square.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 11:55:39 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/10 21:06:30 by victor        ########   odam.nl         */
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

void	parse_square(char **info, t_data *data)
{
	t_object	*object;

	if (char_arrlen(info) != 5)
		print_error("Wrong amount of values given for square", data);
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed for square", data);
	object->type = SQ;
	object->pos[0] = parse_coord(info[1], data);
	object->vector = parse_coord(info[2], data);
	object->size = parse_double(info[3]);
	object->color = parse_color(info[4], data);
	if ((object->vector.x > 1 || object->vector.x < -1) ||
		(object->vector.y > 1 || object->vector.y < -1) ||
		(object->vector.z > 1 || object->vector.z < -1))
		print_error("Invalid orientation vector given for square", data);
	object->vector = vec_normalize(object->vector);
	init_sq_children(object, data);
	free(object);
}
