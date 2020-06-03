/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_normalize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 19:53:50 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/04 19:53:50 by vtenneke      ########   odam.nl         */
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

inline t_vec3d	vec_normalize(t_vec3d vec)
{
	return (vec_new(vec.x / vec_len(vec),
					vec.y / vec_len(vec),
					vec.z / vec_len(vec)));
}
