/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_dist_sp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 11:14:52 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/12 11:14:52 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define DIR ray.direction

t_ray_res	obj_dist_sp(t_object *sphere, t_ray ray)
{
	double	t;
	double	h;
	t_vec3d	l;
	double	d;

	l = vec_a_to_b(ray.origin, sphere->pos);
	t = vec_dot_prod(l, DIR);
	if (t < 0)
		return (ray_res_inf());
	d = sqrt(pow(sphere->size, 2) - pow(t, 2));
	if (d > (sphere->size / 2) || d < 0)
		return (ray_res_inf());
	h = sqrt(pow(sphere->size / 2, 2) - pow(d, 2));
	return (ray_res_dist_new(sphere, vec_sub(vec_add(ray.origin,
		vec_multi(DIR, t)), vec_multi(DIR, h)),
		sphere->color, t - h));
}
// t0 = t - h