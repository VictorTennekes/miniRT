/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norm_sp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 15:00:42 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/18 15:00:42 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Returning the normal of the sphere retrieved from the s_ray_res struct.
**
**	@param	:	{t_ray_res} ray_res
**	@param	:	{t_data *} data
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>

t_vec3d	norm_sp(t_ray_res ray_res, t_ray ray, t_data *data)
{
	(void)data;
	return (adjust_normal(ray.direction, vec_a_to_b(ray_res.object->pos[0], ray_res.position)));
}