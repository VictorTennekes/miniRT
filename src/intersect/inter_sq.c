/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter_sq.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 09:53:54 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/11 09:53:54 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	intersect_sq(t_object *square, t_ray ray, t_data *data)
{
	t_matrix	sq_matrix;
	t_vec3d		corner[4];
	t_vec3d		corner_vec[2];
	t_object	*triangle[2];
	double		res[2];

	
	triangle[0]->type = TR;
	triangle[0]->pos[0] = corner[0];
	triangle[0]->pos[1] = corner[1];
	triangle[0]->pos[2] = corner[2];
	triangle[1]->type = TR;
	triangle[1]->pos[0] = corner[0];
	triangle[1]->pos[1] = corner[1];
	triangle[1]->pos[2] = corner[2];
	res[0] = intersect(triangle[0], ray, data);
	res[1] = intersect(triangle[1], ray, data);
}