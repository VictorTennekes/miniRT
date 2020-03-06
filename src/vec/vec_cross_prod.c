/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_cross_prod.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 11:04:50 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/24 11:04:50 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculating the cross product of two vectors.
**
**	@param	:	{t_vec3d} a
**	@param	:	{t_vec3d} b
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>

inline t_vec3d	vec_cross_prod(t_vec3d vec1, t_vec3d vec2)
{
	return (vec_new((vec1.y * vec2.z) - (vec1.z * vec2.y),
					(vec1.z * vec2.x) - (vec1.x * vec2.z),
					(vec1.x * vec2.y) - (vec1.y * vec2.x)));
}
