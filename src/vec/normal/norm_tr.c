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

t_vec3d	norm_tr(t_ray_res ray_res, t_data *data)
{
	t_vec3d	vec_a;
	t_vec3d	vec_b;

	(void)data;
	vec_a = vec_sub(ray_res.object->pos2, ray_res.object->pos);
	vec_b = vec_sub(ray_res.object->pos3, ray_res.object->pos);
	return (vec_cross_prod(vec_a, vec_b));
}