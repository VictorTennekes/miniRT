/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norm_cy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 10:41:45 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/03 10:41:45 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Returning the normal of the cylinder retrieved from the s_ray_res struct.
**
**	@param	:	{t_ray_res} ray_res
**	@param	:	{t_data *} data
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>

t_vec3d	norm_cy(t_ray_res ray_res, t_data *data)
{
	(void)data;
	return (ray_res.object->vector);
}
