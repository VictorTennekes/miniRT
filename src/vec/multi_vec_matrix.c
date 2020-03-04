/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   multi_vec_matrix.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 14:58:38 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/04 14:58:38 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Multiplying a vector with a matrix
**
**	@param	:	{t_vec3d} vec
**	@param	:	{t_matrix} matrix
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>

t_vec3d		multi_vec_matrix(t_vec3d vec, t_matrix matrix)
{
	t_vec3d new;

	new.x = vec.x * matrix.right.x + vec.y * matrix.up.x + vec.z *
		matrix.forward.x;
	new.y = vec.x * matrix.right.y + vec.y * matrix.up.y + vec.z *
		matrix.forward.y;
	new.z = vec.x * matrix.right.z + vec.y * matrix.up.z + vec.z *
		matrix.forward.z;
	return (new);
}
