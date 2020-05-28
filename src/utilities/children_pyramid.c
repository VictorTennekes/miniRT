/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   children_pyramid.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/25 23:57:40 by victor        #+#    #+#                 */
/*   Updated: 2020/05/25 23:57:40 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

static void	setup_triangles(t_object **triangle, t_vec3d *corners, t_vec3d top_point, t_color color)
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
	square->type = SQ;
	square->pos[0] = pyramid->pos[0];
	square->vector = pyramid->vector;
	square->size = pyramid->size;
	square->color = pyramid->color;
	init_sq_children(square, data);
	init_sq_corners(square, corners);
	top_point = vec_add(pyramid->pos[0], vec_multi(pyramid->vector, pyramid->height));
	setup_triangles(triangle, corners, top_point, pyramid->color);
	if (!lst_new_back(&(data->objects), triangle[0]) || !lst_new_back(&(data->objects), triangle[1])
		|| !lst_new_back(&(data->objects), triangle[2]) || !lst_new_back(&(data->objects), triangle[3]))
		print_error("Allocation failed for square children", data);
}
