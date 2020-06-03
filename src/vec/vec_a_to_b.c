/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_a_to_b.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:18:53 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:18:53 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculating the direction of a vector from point a to point b.
**
**	@param	:	{t_vec3d} a
**	@param	:	{t_vec3d} b
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>

inline t_vec3d	vec_a_to_b(t_vec3d a, t_vec3d b)
{
	return (vec_normalize(vec_sub(b, a)));
}
