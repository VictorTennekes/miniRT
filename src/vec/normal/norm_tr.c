/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norm_tr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 10:57:02 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/05 10:57:02 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Computating the normal of the triangle plane by taking the cross product
**	of 2 lines between points of the triangle.
**
**	@param	:	{t_ray_res} ray_res
**	@param	:	{t_data *} data
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>

t_vec3d	norm_tr(t_ray_res ray_res, t_ray ray, t_data *data)
{
	t_vec3d	vec[3];

	(void)data;
	vec[0] = vec_sub(ray_res.object->pos[1], ray_res.object->pos[0]);
	vec[1] = vec_sub(ray_res.object->pos[2], ray_res.object->pos[0]);
	vec[2] = vec_cross_prod(vec[0], vec[1]);
	return (adjust_normal(ray.direction, vec_normalize(vec[2])));
}
