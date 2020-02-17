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

t_ray_res	obj_dist_sp(t_object *sphere, t_ray ray)
{
	double	d;
	double	t;
	double	h;
	t_vec3d p;

	t = vec_dot_prod(vec_sub(sphere->pos, ray.origin), ray.direction);
	if (t < 0)
		return (ray_res_inf());
	p = vec_add(ray.origin, vec_multi(ray.direction, t));
	d = vec_len(vec_sub(sphere->pos, p));
	if (d < 0)
		return (ray_res_inf());
	if (d < (sphere->size / 2))
		return (ray_res_inf());
	h = sqrt(pow(sphere->size / 2, 2) - pow(d, 2));
	return (ray_res_dist_new(sphere, vec_sub(p, vec_multi(ray.direction, h)), sphere->color, t - h));
}
