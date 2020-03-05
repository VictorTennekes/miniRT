/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter_tr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 11:18:57 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/05 11:18:57 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

bool	intersect_tr(t_object *triangle, t_ray ray, t_data *data)
{
	t_ray_res	tr_plane;
	t_object	plane;

	(void) data;
	plane.type = PL;
	plane.pos = triangle->pos;
	plane.vector = triangle->vector;
	if (vec_dot_prod(plane.vector, ray.direction) <= EPSILON)
		return (false);
	tr_plane = obj_dist(&plane, ray, data);
	if (tr_plane.distance == INFINITY)
		return (false);
	return (check_edge_tr(triangle, plane.vector, tr_plane.position));
}