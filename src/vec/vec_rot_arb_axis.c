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

t_matrix	matrix_mult(t_matrix m1, t_matrix m2)
{
	t_matrix res;
	
	res.right.x = vec_dot_prod(m1.right, vec_new(m2.right.x, m2.up.x, m2.forward.x));
	res.right.y = vec_dot_prod(m1.right, vec_new(m2.right.y, m2.up.y, m2.forward.y));
	res.right.z = vec_dot_prod(m1.right, vec_new(m2.right.z, m2.up.z, m2.forward.z));

	res.up.x = vec_dot_prod(m1.up, vec_new(m2.right.x, m2.up.x, m2.forward.x));
	res.up.y = vec_dot_prod(m1.up, vec_new(m2.right.y, m2.up.y, m2.forward.y));
	res.up.z = vec_dot_prod(m1.up, vec_new(m2.right.z, m2.up.z, m2.forward.z));

	res.forward.x = vec_dot_prod(m1.forward, vec_new(m2.right.x, m2.up.x, m2.forward.x));
	res.forward.y = vec_dot_prod(m1.forward, vec_new(m2.right.y, m2.up.y, m2.forward.y));
	res.forward.z = vec_dot_prod(m1.forward, vec_new(m2.right.z, m2.up.z, m2.forward.z));
	
	res.right.x = vec_dot_prod(m1.right, vec_new(0, 1, 0));
	res.right.y = vec_dot_prod(m1.right, vec_new(0, 1, 0));
	res.right.z = vec_dot_prod(m1.right, vec_new(0, 1, 0));

	res.up.x = vec_dot_prod(m1.up, vec_new(0, 1, 0));
	res.up.y = vec_dot_prod(m1.up, vec_new(0, 1, 0));
	res.up.z = vec_dot_prod(m1.up, vec_new(0, 1, 0));

	res.forward.x = vec_dot_prod(m1.forward, vec_new(0, 1, 0));
	res.forward.y = vec_dot_prod(m1.forward, vec_new(0, 1, 0));
	res.forward.z = vec_dot_prod(m1.forward, vec_new(0, 1, 0));
	return (res);

}

t_matrix4d	matrix_mult(t_matrix m1, t_matrix m2)
{
	t_matrix res;
	
	res.right.x = vec_dot_prod(m1.right, vec_new(m2.right.x, m2.up.x, m2.forward.x));
	res.right.y = vec_dot_prod(m1.right, vec_new(m2.right.y, m2.up.y, m2.forward.y));
	res.right.z = vec_dot_prod(m1.right, vec_new(m2.right.z, m2.up.z, m2.forward.z));

	res.up.x = vec_dot_prod(m1.up, vec_new(m2.right.x, m2.up.x, m2.forward.x));
	res.up.y = vec_dot_prod(m1.up, vec_new(m2.right.y, m2.up.y, m2.forward.y));
	res.up.z = vec_dot_prod(m1.up, vec_new(m2.right.z, m2.up.z, m2.forward.z));

	res.forward.x = vec_dot_prod(m1.forward, vec_new(m2.right.x, m2.up.x, m2.forward.x));
	res.forward.y = vec_dot_prod(m1.forward, vec_new(m2.right.y, m2.up.y, m2.forward.y));
	res.forward.z = vec_dot_prod(m1.forward, vec_new(m2.right.z, m2.up.z, m2.forward.z));
	
	res.right.x = vec_dot_prod(m1.right, vec_new(0, 1, 0));
	res.right.y = vec_dot_prod(m1.right, vec_new(0, 1, 0));
	res.right.z = vec_dot_prod(m1.right, vec_new(0, 1, 0));

	res.up.x = vec_dot_prod(m1.up, vec_new(0, 1, 0));
	res.up.y = vec_dot_prod(m1.up, vec_new(0, 1, 0));
	res.up.z = vec_dot_prod(m1.up, vec_new(0, 1, 0));

	res.forward.x = vec_dot_prod(m1.forward, vec_new(0, 1, 0));
	res.forward.y = vec_dot_prod(m1.forward, vec_new(0, 1, 0));
	res.forward.z = vec_dot_prod(m1.forward, vec_new(0, 1, 0));
	return (res);

}

t_matrix	matrix_rot_x(t_matrix og, double angle)
{
	t_matrix res;

	res.right = vec_new(1, 0, 0);
	res.up = vec_new(0, cos(angle), -sin(angle));
	res.forward = vec_new(0, sin(angle), cos(angle));
	res = matrix_mult(og, res);
	normal_matrix(res);
	return (res);
}

t_matrix	matrix_rot_y(t_matrix og, double angle)
{
	t_matrix	res;

	(void)og;
	res.right = vec_new(cos(angle), 0, sin(angle));
	res.up = vec_new(0, 1, 0);
	res.forward = vec_new(-sin(angle), 0, cos(angle));
	printf("CAM MATRIX\nforward_x: %f\nforward_y: %f\nforward_z: %f\n", res.forward.x, res.forward.y, res.forward.z);
	res = matrix_mult(og, res);
	printf("CAM MATRIX\nforward_x: %f\nforward_y: %f\nforward_z: %f\n", res.forward.x, res.forward.y, res.forward.z);
	normal_matrix(res);
	return(res);
}