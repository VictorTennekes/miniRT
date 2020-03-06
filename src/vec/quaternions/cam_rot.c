/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cam_rot.c                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:38:54 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/06 15:37:37 by aaugusti         ###   ########.fr       */
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

#define P0 (p[0])
#define P1 (p[1])
#define R0 (r[0])
#define R1 (r[1])

t_quat	rotate_cam(t_vec3d vector, t_vec3d axis, double angle)
{
	t_quat	p[2];
	t_quat	r[2];

	P0 = quat_new(0, vector.x, vector.y, vector.z);
	R0 = quat_local_rot(axis, angle);
	R1 = quat_conj(R0);
	P1 = quat_multi(quat_multi(R0, P0), R1);
	return (P1);
}
