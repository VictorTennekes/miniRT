/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   children_pyramid.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:17:00 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:17:00 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Splitting a pyramid into its respective objects: 1 square and 4 triangles.
**
**	@param	:	{t_object *} pyramid
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <stdlib.h>

static void	setup_triangles(t_object **triangle, t_vec3d *corners,
	t_vec3d top_point, t_color color)
{
	triangle[0]->type = TR;
	triangle[0]->pos[0] = corners[1];
	triangle[0]->pos[1] = corners[0];
	triangle[0]->pos[2] = top_point;
	triangle[0]->color = color;
	triangle[1]->type = TR;
	triangle[1]->pos[0] = corners[3];
	triangle[1]->pos[1] = corners[1];
	triangle[1]->pos[2] = top_point;
	triangle[1]->color = color;
	triangle[2]->type = TR;
	triangle[2]->pos[0] = corners[0];
	triangle[2]->pos[1] = corners[2];
	triangle[2]->pos[2] = top_point;
	triangle[2]->color = color;
	triangle[3]->type = TR;
	triangle[3]->pos[0] = corners[2];
	triangle[3]->pos[1] = corners[3];
	triangle[3]->pos[2] = top_point;
	triangle[3]->color = color;
}

void		init_py_children(t_object *pyramid, t_data *data)
{
	t_object	*triangle[4];
	t_object	*square;
	t_vec3d		corners[4];
	t_vec3d		top_point;

	triangle[0] = (t_object *)malloc(sizeof(t_object));
	triangle[1] = (t_object *)malloc(sizeof(t_object));
	triangle[2] = (t_object *)malloc(sizeof(t_object));
	triangle[3] = (t_object *)malloc(sizeof(t_object));
	square = (t_object *)malloc(sizeof(t_object));
	if (!triangle[0] || !triangle[1] || !triangle[2] || !triangle[3] || !square)
		print_error("Malloc failed for pyramid children", data);
	*square = *pyramid;
	square->type = SQ;
	init_sq_children(square, data);
	init_sq_corners(square, corners);
	top_point = vec_add(pyramid->pos[0],
		vec_multi(pyramid->vector, pyramid->height));
	setup_triangles(triangle, corners, top_point, pyramid->color);
	if (!lst_new_back(&(data->objects), triangle[0]) ||
		!lst_new_back(&(data->objects), triangle[1]) ||
		!lst_new_back(&(data->objects), triangle[2]) ||
		!lst_new_back(&(data->objects), triangle[3]))
		print_error("Allocation failed for square children", data);
}
