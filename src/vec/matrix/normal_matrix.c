/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal_matrix.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 18:59:33 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/24 18:59:33 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Normalizing a matrix by narmmalizing it's individual components.
**
**	@param	:	{t_matrix} matrix
**
**	@return	:	{t_matrix}
*/

#include <minirt.h>

t_matrix	normal_matrix(t_matrix matrix)
{
	matrix.forward = vec_normalize(matrix.forward);
	matrix.right = vec_normalize(matrix.right);
	matrix.up = vec_normalize(matrix.up);
	return (matrix);
}
