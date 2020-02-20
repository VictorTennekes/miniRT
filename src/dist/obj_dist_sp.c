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
#define CAM data->current_cam

t_ray_res	obj_dist_sp(t_object *sphere, t_ray ray, t_data *data)
{
	double	t;
	double	y;
	double	x;
	t_vec3d	p;

	(void)data;
	t = vec_dot_prod(vec_sub(sphere->pos, CAM->pos), DIR);
	if (t < 0)
		return (ray_res_inf());
	p = vec_add(CAM->pos, vec_multi(DIR, t));
	y = vec_len(vec_sub(sphere->pos, p));
	if (y > sphere->size / 2)
		return (ray_res_inf());
	x = sqrt(pow(sphere->size / 2, 2) - pow(y, 2));
	return (ray_res_dist_new(sphere,
					vec_sub(p, vec_multi(ray.direction, x)), sphere->color, t - x));
}
// t0 = t - h