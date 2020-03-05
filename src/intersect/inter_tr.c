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

bool	check_edge_tr(t_object *triangle, t_vec3d p)
{
	t_vec3d c;

	c = (vec_cross_prod(vec_sub(triangle->pos2, triangle->pos),
		vec_sub(p, triangle->pos)));
	if (vec_dot_prod(triangle->vector, c) < 0)
		return (false);
	c = (vec_cross_prod(vec_sub(triangle->pos3, triangle->pos2),
		vec_sub(p, triangle->pos2)));
	if (vec_dot_prod(triangle->vector, c) < 0)
		return (false);
	c = (vec_cross_prod(vec_sub(triangle->pos, triangle->pos3),
		vec_sub(p, triangle->pos3)));
	if (vec_dot_prod(triangle->vector, c) < 0)
		return (false);
	return (true);
}

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
	if (fabs(vec_dot_prod(triangle->vector, ray.origin)) < 1e-6)
		return (false);
	d = vec_dot_prod(triangle->vector, triangle->pos);
	t = (vec_dot_prod(ray.origin, triangle->vector) + d) / vec_dot_prod(triangle->vector, ray.origin);
	if (t < 0)
		return (false);
	p = vec_add(ray.origin, vec_multi(ray.direction, t));
	printf("myes? %f\n", p.x);
	if (check_edge_tr(triangle, p) == false)
		return (false);
	return (true);
}