/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_sub.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 21:24:03 by victor         #+#    #+#                */
/*   Updated: 2020/02/10 21:26:19 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Subtracting two vectors.
**
**	@param	:	{t_vec3d} vec1
**	@param	:	{t_vec3d} vec2
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>

t_vec3d	vec_sub(t_vec3d vec1, t_vec3d vec2)
{
	return (vec_new(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z));
}