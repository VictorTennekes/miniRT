/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_normalize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:04:40 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/10 20:47:28 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Normalizing a vector.
**
**	@param	:	{t_vec3d} vec
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>
#include <math.h>

t_vec3d vec_normalize(t_vec3d vec)
{
	return (vec_new(vec.x / vec_len(vec),
					vec.y / vec_len(vec),
					vec.z / vec_len(vec)));
}