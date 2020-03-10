/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_dist_pl.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 14:25:08 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/20 14:25:08 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculate the distance between the ray origin and a plane.
**
**	@param	:	{t_object *} plane
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{t_ray_res}
*/

#include <minirt.h>

t_ray_res	obj_dist_pl(t_object *plane, t_ray ray, t_data *data)
{
	double	denom;
	double	t;

	(void)data;
	denom = vec_dot_prod(plane->vector, ray.direction);
	t = (vec_dot_prod(vec_sub(plane->pos[0], ray.origin), plane->vector) /
		denom);
	if (t < 0)
		return (ray_res_inf());
	return (ray_res_dist_new(plane, vec_add(ray.origin,
					vec_multi(ray.direction, t)), plane->color, t));
}
