/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_conj.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:41:50 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/04 13:41:50 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Creating the conjugate of a given quaternion.
**
**	@param	:	{t_quat} quat
**
**	@return	:	{t_quat}
*/

#include <minirt.h>

inline t_quat	quat_conj(t_quat quat)
{
	return (quat_new(quat.w, -quat.x, -quat.y, -quat.z));
}
