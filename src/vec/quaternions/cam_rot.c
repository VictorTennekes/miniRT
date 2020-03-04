/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cam_rot.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:38:54 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/04 13:38:54 by vtenneke      ########   odam.nl         */
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

t_quat rotate_cam(t_vec3d vector, t_vec3d axis, double angle)
{
	t_quat	p;
	t_quat	p2;
	t_quat	r;
	t_quat	r2;

	p = quat_new(0, vector.x, vector.y, vector.z);
	vector = vec_normalize(vector);
	axis = vec_normalize(axis);
	r = quat_local_rot(axis, angle);
	r2 = quat_conj(r);
	p2 = quat_multi(quat_multi(r, p), r2);
	return (p2);
}