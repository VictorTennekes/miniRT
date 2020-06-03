/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_sq_corners.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:17:42 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:17:42 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

void	init_sq_corners(t_object *square, t_vec3d *corners)
{
	t_matrix	sq_matrix;
	t_vec3d		corner_vec[2];

	if (square->vector.x == 0 && (square->vector.y == 1 || square->vector.y == -1) && square->vector.z == 0)
	{
		sq_matrix.forward = vec_new(0, square->vector.y == 1 ? 1 : -1, 0);
		sq_matrix.right = vec_new(1, 0, 0);
		sq_matrix.up = vec_new(0, 0, 1);
	}
	else
	{
		sq_matrix = matrix_new(square->vector);
	}
	corner_vec[0] = vec_multi(sq_matrix.up, 0.5 * square->size);
	corner_vec[1] = vec_multi(sq_matrix.right, 0.5 * square->size);
	corners[0] = vec_add(square->pos[0], vec_add(corner_vec[0], corner_vec[1]));
	corners[1] = vec_add(square->pos[0], vec_sub(corner_vec[0], corner_vec[1]));
	corners[2] = vec_sub(square->pos[0], vec_sub(corner_vec[0], corner_vec[1]));
	corners[3] = vec_sub(square->pos[0], vec_add(corner_vec[0], corner_vec[1]));
}