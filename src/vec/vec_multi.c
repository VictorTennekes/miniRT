/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_multi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 15:48:33 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/12 15:48:33 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Multiplying a vector with a factor.
**
**	@param	:	{t_vec3d} vec
**	@param	:	{double} factor
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>

inline t_vec3d	vec_multi(t_vec3d vec, double factor)
{
	return (vec_new(vec.x * factor, vec.y * factor, vec.z * factor));
}
