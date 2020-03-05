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

#include  <minirt.h>

t_ray_res	obj_dist_tr(t_object *triangle, t_ray ray, t_data *data)
{
	double	t;
	double	d;
	double	area;

	(void)data;
	triangle->vector = vec_cross_prod(vec_sub(triangle->pos2,
		triangle->pos), vec_sub(triangle->pos3,
		triangle->pos));
	area = vec_len(triangle->vector);
	if (fabs(vec_dot_prod(triangle->vector, ray.origin)) < EPSILON)
		return (ray_res_inf());
	d = vec_dot_prod(triangle->vector, triangle->pos);
	t = (vec_dot_prod(ray.origin, triangle->vector) + d) / vec_dot_prod(triangle->vector, ray.origin);
	if (t < 0)
		return (ray_res_inf());
	return (ray_res_dist_new(triangle, vec_add(ray.origin,
					vec_multi(ray.direction, t)), triangle->color, t));
}
