/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_triangle.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 16:18:44 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/04 11:43:37 by vtenneke      ########   odam.nl         */
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

void	parse_triangle(char **info, t_data *data)
{
	t_object *object;

	if (char_arrlen(info) != 5)
		print_error("Invalid amount of values given for cylinder", data);
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed for triangle", data);
	object->type = TR;
	object->pos[0] = parse_coord(info[1]);
	object->pos[1] = parse_coord(info[2]);
	object->pos[2] = parse_coord(info[3]);
	object->color = parse_color(info[4], data);
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed for triangle", data);
}
