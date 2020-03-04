/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:56:02 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/04 13:56:02 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Creating a new movement matrix following the forward vector given.
**
**	@param	:	{t_vec3d} vec
**
**	@return	:	{t_matrix}
*/

#include <minirt.h>

t_matrix matrix_new(t_vec3d vec)
{
	t_matrix	matrix;

	matrix.forward = vec_multi(vec, -1);
	matrix.right = vec_cross_prod(vec_normalize(vec_new(0, 1, 0)),
					matrix.forward);
	matrix.up = vec_cross_prod(matrix.forward, matrix.right);
	normal_matrix(matrix);
	return (matrix);
}