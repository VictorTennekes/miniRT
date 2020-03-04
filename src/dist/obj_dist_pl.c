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
**	Calculating the distance between the ray origin and a plane.
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
	double	t;

	(void)data;
	t = (vec_dot_prod(vec_sub(plane->pos, ray.origin), plane->vector) /
					vec_dot_prod(ray.direction, plane->vector));
	if (t < 0)
		return (ray_res_inf());
	return(ray_res_dist_new(plane, vec_add(ray.origin,
					vec_multi(ray.direction, t)), plane->color, t));
}