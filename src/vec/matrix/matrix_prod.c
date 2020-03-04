/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_prod.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:38:03 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/04 13:38:03 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Multiplying a matrix with another matrix.
**
**	@param	:	{t_matrix} a
**	@param	:	{t_matrix} b
**
**	@return	:	{t_matrix}
*/

#include <minirt.h>

t_matrix	matrix_prod(t_matrix a, t_matrix b)
{
	t_matrix new;

	new.right.x = a.right.x * b.right.x + a.up.x * b.right.y + a.forward.x *
		b.right.z;
	new.right.y = a.right.y * b.right.x + a.up.y * b.right.y + a.forward.y *
		b.right.z;
	new.right.z = a.right.z * b.right.x + a.up.z * b.right.y + a.forward.z *
		b.right.z;
	new.up.x = a.right.x * b.up.x + a.up.x * b.up.y + a.forward.x * b.up.z;
	new.up.y = a.right.y * b.up.x + a.up.y * b.up.y + a.forward.y * b.up.z;
	new.up.z = a.right.z * b.up.x + a.up.z * b.up.y + a.forward.z * b.up.z;
	new.forward.x = a.right.x * b.forward.x + a.up.x * b.forward.y +
		a.forward.x * b.forward.z;
	new.forward.y = a.right.y * b.forward.x + a.up.x * b.forward.y +
		a.forward.y * b.forward.z;
	new.forward.z = a.right.y * b.forward.x + a.up.x * b.forward.y +
		a.forward.z * b.forward.z;
	return (new);
}
