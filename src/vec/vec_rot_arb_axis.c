/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_rot_arb_axis.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 15:53:13 by victor         #+#    #+#                */
/*   Updated: 2020/02/26 15:53:13 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	vec_rot_arb_axis(t_vec3d vec, t_vec3d axis, double angle)
{
	t_matrix matrix;

	matrix.right.x = (cos(angle) + vec.x * (1 - cos(angle)));
	matrix.right.y = axis.x * axis.y * (1 - cos(angle)) - axis.z * sin(angle);
	matrix.right.z = axis.x * axis.y * (1 - cos(angle)) + axis.y * sin(angle);

	matrix.up.x = axis.y * axis.x * (1 - cos(angle)) + axis.z * sin(angle);
	matrix.up.y = cos(angle) + vec.y * (1 - cos(angle));
	matrix.up.z = axis.y * axis.z * (1 - cos(angle)) - axis.x * sin(angle);

	matrix.forward.x = axis.z * axis.x * (1 - cos(angle)) - axis.y * sin(angle);
	matrix.forward.y = axis.z * axis.y * (1 - cos(angle)) + axis.x * sin(angle);
	matrix.forward.z = cos(angle) + vec.z * (1 - cos(angle));
}