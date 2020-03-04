/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 21:12:19 by victor         #+#    #+#                */
/*   Updated: 2020/02/10 21:13:10 by victor        ########   odam.nl         */
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

t_vec3d	vec_new(double x, double y, double z)
{
	t_vec3d vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}