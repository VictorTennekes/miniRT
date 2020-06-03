/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter_ds.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 10:58:15 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/10 10:58:15 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	intersect_ds(t_object *disk, t_ray ray, t_data *data)
{
	double		t;
	t_vec3d		p;
	t_object	plane;

	plane.type = PL;
	plane.pos[0] = disk->pos[0];
	plane.vector = disk->vector;
	// if (vec_dot_prod(plane.vector, ray.direction) <= 0)
	// 	plane.vector = vec_multi(plane.vector, -1);
	t = intersect(&plane, ray, data);
	if (t == INFINITY)
		return (INFINITY);
	p = vec_add(ray.origin, vec_multi(ray.direction, t));
	if (vec_dist(p, disk->pos[0]) > disk->size / 2)
		return (INFINITY);
	return (t);
}