/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_sq_children.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:17:34 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:17:34 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Initializing the children of a square and adding them to the linked list.
**
**	@param	:	{t_object *} square
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <stdlib.h>
#include <liblist.h>

void		init_sq_children(t_object *square, t_data *data)
{
	t_object	*triangle[2];
	t_vec3d		corners[4];

	(void)data;
	triangle[0] = (t_object *)malloc(sizeof(t_object));
	triangle[1] = (t_object *)malloc(sizeof(t_object));
	if (!triangle[0] || !triangle[1])
		print_error("Malloc failed for square children", data);
	init_sq_corners(square, corners);
	triangle[0]->type = TR;
	triangle[0]->pos[0] = corners[0];
	triangle[0]->pos[1] = corners[1];
	triangle[0]->pos[2] = corners[2];
	triangle[0]->color = square->color;
	triangle[1]->type = TR;
	triangle[1]->pos[0] = corners[1];
	triangle[1]->pos[1] = corners[2];
	triangle[1]->pos[2] = corners[3];
	triangle[1]->color = square->color;
	if (!lst_new_back(&(data->objects), triangle[0]) ||
		!lst_new_back(&(data->objects), triangle[1]))
		print_error("Allocation failed for square children", data);
}
