/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_multi.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:37:24 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/04 13:37:24 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Multiplying a matrix with a factor.
**
**	@param	:	{t_matrix} matrix
**	@param	:	{double} factor
**
**	@return	:	{t_matrix}
*/

#include <minirt.h>

t_matrix	matrix_multi(t_matrix matrix, double factor)
{
	t_matrix res;

	res.forward = vec_multi(matrix.forward, factor);
	res.up = vec_multi(matrix.up, factor);
	res.right = vec_multi(matrix.right, factor);
	return (res);
}