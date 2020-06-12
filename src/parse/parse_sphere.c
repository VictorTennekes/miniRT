/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 16:55:45 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/06 13:28:34 by vtenneke      ########   odam.nl         */
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

void	parse_sphere(char **info, t_data *data)
{
	t_object *object;

	if (char_arrlen(info) != 4)
		print_error("Invalid amount of values given for sphere", data);
	object = (t_object *)malloc(sizeof(t_object));
	ft_bzero(object, sizeof(t_object));
	if (!object)
		print_error("Malloc failed for sphere", data);
	object->type = SP;
	object->pos[0] = parse_coord(info[1], data);
	object->size = parse_double(info[2]);
	object->color = parse_color(info[3], data);
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed for sphere", data);
}
