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

bool	intersect_tr(t_object *triangle, t_ray ray, t_data *data)
{
	double	t;
	double	d;
	double	area;
	t_vec3d	p;

	(void)data;
	triangle->vector = vec_cross_prod(vec_sub(triangle->pos2,
		triangle->pos), vec_sub(triangle->pos3,
		triangle->pos));
	area = vec_len(triangle->vector);
	printf("myes? %f\n", vec_dot_prod(triangle->vector, ray.origin));
	if (vec_dot_prod(triangle->vector, ray.origin) < EPSILON)
		return (false);
	d = vec_dot_prod(triangle->vector, triangle->pos);
	t = (vec_dot_prod(ray.origin, triangle->vector) + d) /
		vec_dot_prod(triangle->vector, ray.origin);
	if (t < 0)
		return (false);
	p = vec_add(ray.origin, vec_multi(ray.direction, t));
	if (check_edge_tr(triangle, p) == false)
		return (false);
	return (true);
}