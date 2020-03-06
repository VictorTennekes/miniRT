/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cam_rot.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:38:54 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/06 15:37:37 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Rotating a quaternion around a arbitrary axis by applying a couple
**	of calculations.
**
**	@param	:	{t_vec3d} vector
**	@param	:	{t_vec3d} axis
**	@param	:	{double} angle
**
**	@return	:	{t_quat}
*/

#include <minirt.h>

t_quat	rotate_cam(t_vec3d vector, t_vec3d axis, double angle)
{
	t_quat	p[2];
	t_quat	r[2];

	p[0] = quat_new(0, vector.x, vector.y, vector.z);
	r[0] = quat_local_rot(axis, angle);
	r[1] = quat_conj(r[0]);
	p[1] = quat_multi(quat_multi(r[0], p[0]), r[1]);
	return (p[1]);
}
