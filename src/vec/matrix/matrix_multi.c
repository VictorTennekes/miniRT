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

#include <minirt.h>

t_matrix	matrix_multi(t_matrix m, double d)
{
	t_matrix res;

	res.forward = vec_multi(m.forward, d);
	res.up = vec_multi(m.up, d);
	res.right = vec_multi(m.right, d);
	return (res);
}