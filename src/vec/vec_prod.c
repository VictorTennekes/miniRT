/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_prod.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 10:45:51 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/27 10:45:51 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculating the product of two vectors.
**
**	@param	:	{t_vec3d} vec1
**	@param	:	{t_vec3d} vec2
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>

inline t_vec3d	vec_prod(t_vec3d vec1, t_vec3d vec2)
{
	return (vec_new(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z));
}
