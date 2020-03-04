/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_local_rot.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:43:32 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/04 13:43:32 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculating the local rotation of a quaternion around a arbitrary axis
**	compared to its previous state.
**
**	@param	:	{t_vec3d} axis
**	@param	:	{double} angle
**
**	@return	:	{t_quat}
*/

#include <minirt.h>

t_quat	quat_local_rot(t_vec3d axis, double angle)
{
	t_quat	res;

	axis = vec_normalize(axis);
	res.w = cos(angle / 2);
	res.x = axis.x * sin(angle / 2);
	res.y = axis.y * sin(angle / 2);
	res.z = axis.z * sin(angle / 2);
	return (res);
}
