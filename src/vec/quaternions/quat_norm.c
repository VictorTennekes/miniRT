/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_norm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:42:16 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/04 13:42:16 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Normalizing a quaternion.
**
**	@param	:	{t_quat} quat
**
**	@return	:	{t_quat}
*/

#include <minirt.h>

t_quat	quat_norm(t_quat quat)
{
	t_quat	new;
	double	mag;

	mag = sqrt(pow(quat.w, 2) + pow(quat.x, 2) + pow(quat.y, 2) +
		pow(quat.z, 2));
	new.w = quat.w / mag;
	new.x = quat.x / mag;
	new.y = quat.y / mag;
	new.z = quat.z / mag;
	return (new);
}
