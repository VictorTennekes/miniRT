/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norm_ds.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 12:26:13 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/10 12:26:13 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Adjust the normal of a disk so lighting works correctly
**
**	@param	:	{t_ray_res} ray_res
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>

t_vec3d norm_ds(t_ray_res ray_res, t_ray ray, t_data  *data)
{
	(void)data;
	return (adjust_normal(ray.direction, ray_res.object->vector));
}