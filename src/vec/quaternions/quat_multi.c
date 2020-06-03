/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_multi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:43:55 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/04 13:43:55 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Multiplying quaternion with another quaternion.
**
**	@param	:	{t_quat} q1
**	@param	:	{t_quat} q2
**
**	@return	:	{t_quat}
*/

#include <minirt.h>

t_quat	quat_multi(t_quat q1, t_quat q2)
{
	t_quat res;

	res.w = ((q1.w * q2.w) - (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z));
	res.x = ((q1.w * q2.x) + (q1.x * q2.w) + (q1.y * q2.z) - (q1.z * q2.y));
	res.y = ((q1.w * q2.y) - (q1.x * q2.z) + (q1.y * q2.w) + (q1.z * q2.x));
	res.z = ((q1.w * q2.z) + (q1.x * q2.y) - (q1.y * q2.x) + (q1.z * q2.w));
	return (res);
}
