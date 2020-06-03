/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_sub.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:19:43 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:19:43 by vtenneke      ########   odam.nl         */
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

inline t_vec3d	vec_sub(t_vec3d vec1, t_vec3d vec2)
{
	return (vec_new(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z));
}
