/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:42:33 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/04 13:42:33 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Creating a new quaternion from given parameters.
**
**	@param	:	{double} w
**	@param	:	{double} x
**	@param	:	{double} y
**	@param	:	{double} z
**
**	@return	:	{t_quat}
*/

#include <minirt.h>

t_quat	quat_new(double w, double x, double y, double z)
{
	t_quat new;

	new.w = w;
	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}