/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter_tr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 11:18:57 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/05 11:18:57 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

double	intersect_tr(t_object *triangle, t_ray ray, t_data *data)
{
	t_ray_res	tr_plane;
	t_object	plane;

	plane.type = PL;
	plane.pos[0] = triangle->pos[0];
	plane.vector = normal(ray_res_new(triangle, vec_new(0, 0, 0),
		triangle->color), ray, data);
	if (vec_dot_prod(plane.vector, ray.direction) <= 0)
		plane.vector = vec_multi(plane.vector, -1);
	tr_plane = obj_dist(&plane, ray, data);
	if (!check_edge_tr(triangle, plane.vector, tr_plane.position))
		return (INFINITY);
	return (tr_plane.distance);
}