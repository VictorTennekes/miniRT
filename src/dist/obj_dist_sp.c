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
	double tmp;
	t_vec3d	l;
	t_vec3d	p;

	l = vec_sub(sphere->pos, ray.origin);
	t = vec_dot_prod(l, ray.direction);
	if (t < 0)
		return (ray_res_inf());
	tmp = vec_len(l);
	d = sqrt(pow(tmp, 2) - pow(t, 2));
	if (d < 0)
		return (ray_res_inf());
	if (d < (sphere->size / 2))
		return (ray_res_inf());
	h = sqrt(pow(sphere->size / 2, 2) - pow(d, 2));
	return (ray_res_dist_new(sphere, /*stuff*/, sphere->color, t - h);
}