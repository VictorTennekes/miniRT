/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   children_square.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 10:29:39 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/11 10:29:39 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

static void	init_sq_corners(t_object *square, t_vec3d *corners)
{
	t_matrix	sq_matrix;
	t_vec3d		corner_vec[2];

	sq_matrix = matrix_new(square->vector);
	corner_vec[0] = vec_add(square->pos[0], vec_multi(sq_matrix.up, 0.5 * square->size));
	corner_vec[1] = vec_add(square->pos[0], vec_multi(sq_matrix.right, 0.5 * square->size));
	corners[0] = vec_add(square->pos[0], vec_add(corner_vec[0], corner_vec[1]));
	corners[1] = vec_add(square->pos[0], vec_sub(corner_vec[0], corner_vec[1]));
	corners[2] = vec_sub(square->pos[0], vec_sub(corner_vec[0], corner_vec[1]));
	corners[3] = vec_sub(square->pos[0], vec_add(corner_vec[0], corner_vec[1]));
}

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
	printf("corner[0]	x:%f	y:%f	z:%f\n", corners[0].x, corners[0].y, corners[0].z);
	printf("corner[1]	x:%f	y:%f	z:%f\n", corners[1].x, corners[1].y, corners[1].z);
	printf("corner[2]	x:%f	y:%f	z:%f\n", corners[2].x, corners[2].y, corners[2].z);
	printf("corner[3]	x:%f	y:%f	z:%f\n", corners[3].x, corners[3].y, corners[3].z);
	if (!lst_new_back(&(data->objects), triangle[0]) ||
		!lst_new_back(&(data->objects), triangle[1]))
		print_error("Allocation failed for square children", data);
}