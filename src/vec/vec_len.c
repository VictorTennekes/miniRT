/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_len.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:19:19 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:19:19 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculating the length of a vector.
**
**	@param	:	{t_vec3d} vec
**
**	@return	:	{double}
*/

#include <minirt.h>

inline double	vec_len(t_vec3d vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}
