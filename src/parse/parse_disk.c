/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_disk.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:33:24 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/10 11:33:24 by vtenneke      ########   odam.nl         */
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

void	parse_disk(char **info, t_data *data)
{
	t_object *object;

	if (char_arrlen(info) != 5)
		print_error("Invalid amount of values given for disk", data);
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed for disk", data);
	object->type = DS;
	object->pos[0] = parse_coord(info[1]);
	object->vector = parse_coord(info[2]);
	if ((object->vector.x > 1 || object->vector.x < -1) ||
		(object->vector.y > 1 || object->vector.y < -1) ||
		(object->vector.z > 1 || object->vector.z < -1))
		print_error("Invalid orientation vector given for disk", data);
	object->vector = vec_normalize(object->vector);
	object->size = parse_double(info[3]);
	object->color = parse_color(info[4], data);
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed for disk", data);
}
