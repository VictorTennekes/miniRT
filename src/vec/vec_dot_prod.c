/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_dot_prod.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 13:18:52 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/12 13:18:52 by vtenneke      ########   odam.nl         */
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

inline double	vec_dot_prod(t_vec3d vec1, t_vec3d vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}
