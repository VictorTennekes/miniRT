/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 15:11:11 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/18 15:11:11 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	light(t_ray_res ray_res, t_ray ray, t_light *light, t_data *data)
{
	t_vec3d	norm;
	t_vec3d light_dir;
	double	fac;

	(void)data;
	(void)ray;
	light_dir = vec_a_to_b(ray_res.position, light->pos);
	norm = norm_sp(ray_res.position, ray_res.object->pos);
	fac = vec_dot_prod(light_dir, norm);
	if (fac < 0)
		return (parse_color("0,0,0"));
	fac *= light->ratio;
	fac /= 4 * M_PI * pow(vec_dist(light->pos, ray_res.position), 2);
	return (color_multi(color_mix_light(light->color, ray_res.object->color), fmin(fac, 1)));
}