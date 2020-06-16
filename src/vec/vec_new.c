/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:19:29 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:19:29 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculating the dot product of two vectors.
**
**	@param	:	{t_vec3d} vec1
**	@param	:	{t_vec3d} vec2
**
**	@return	:	{double}
*/

#include <minirt.h>

inline t_vec3d	vec_new(double x, double y, double z)
{
	t_vec3d res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}
