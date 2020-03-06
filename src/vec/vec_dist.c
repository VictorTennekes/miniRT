/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_dist.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 22:16:16 by victor         #+#    #+#                */
/*   Updated: 2020/02/18 22:16:16 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculating the distance between two vectors.
**
**	@param	:	{t_vec3d} vec1
**	@param	:	{t_vec3d} vec2
**
**	@return	:	{double}
*/

#include <minirt.h>

inline double	vec_dist(t_vec3d vec1, t_vec3d vec2)
{
	return (sqrt(pow(vec2.x - vec1.x, 2) +
					pow(vec2.y - vec1.y, 2) +
					pow(vec2.z - vec1.z, 2)));
}
