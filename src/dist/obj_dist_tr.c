/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_dist_tr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 11:29:27 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/05 11:29:27 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

t_ray_res		obj_dist_tr(t_object *triangle, t_ray ray, t_data *data)
{
	t_ray_res	tr_plane;
	t_object	plane;

	plane.type = PL;
	plane.pos = triangle->pos;
	plane.vector = normal(ray_res_new(triangle, vec_new(0, 0, 0), color_new(0, 0, 0)), data);
	if (vec_dot_prod(plane.vector, ray.direction) <= EPSILON)
		return (ray_res_inf());
	plane.vector = plane.vector;
	tr_plane = obj_dist(&plane, ray, data);
	if (tr_plane.distance == INFINITY)
		return (ray_res_inf());
	if (!check_edge_tr(triangle, plane.vector, tr_plane.position))
		return (ray_res_inf());
	return (ray_res_dist_new(triangle, tr_plane.position, triangle->color,
		vec_dist(ray.origin, tr_plane.position)));
}