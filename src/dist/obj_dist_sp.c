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

/*
**	Calculate the distance between the ray origin and a sphere.
**
**	@param	:	{t_object *} sphere
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{t_ray_res}
*/

#include <minirt.h>

t_ray_res	obj_dist_sp(t_object *sphere, t_ray ray, t_data *data)
{
	double	t;
	double	y;
	double	x;
	t_vec3d	p;

	(void)data;
	t = vec_dot_prod(vec_sub(sphere->pos, ray.origin), ray.direction);
	if (t < 0)
		return (ray_res_inf());
	p = vec_add(ray.origin, vec_multi(ray.direction, t));
	y = vec_len(vec_sub(sphere->pos, p));
	if (y > sphere->size / 2)
		return (ray_res_inf());
	x = sqrt(pow(sphere->size / 2, 2) - pow(y, 2));
	return (ray_res_dist_new(sphere,
					vec_sub(p, vec_multi(ray.direction, x)), sphere->color, t - x));
}
// t0 = t - h