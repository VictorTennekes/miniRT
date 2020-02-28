/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quaternions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 13:50:09 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/28 13:50:09 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// w amount
// xyz axis

t_matrix	matrix_multi(t_matrix m, double d)
{
	t_matrix res;

	res.forward = vec_multi(m.forward, d);
	res.up = vec_multi(m.up, d);
	res.right = vec_multi(m.right, d);
	return (res);
}

t_matrix	matrix_prod(t_matrix a, t_matrix b)
{
	t_matrix new;

	new.right.x = a.right.x * b.right.x + a.up.x * b.right.y + a.forward.x * b.right.z;
	new.right.y = a.right.y * b.right.x + a.up.y * b.right.y + a.forward.y * b.right.z;
	new.right.z = a.right.z * b.right.x + a.up.z * b.right.y + a.forward.z * b.right.z;
	new.up.x = a.right.x * b.up.x + a.up.x * b.up.y + a.forward.x * b.up.z;
	new.up.y = a.right.y * b.up.x + a.up.y * b.up.y + a.forward.y * b.up.z;
	new.up.z = a.right.z * b.up.x + a.up.z * b.up.y + a.forward.z * b.up.z;
	new.forward.x = a.right.x * b.forward.x + a.up.x * b.forward.y + a.forward.x * b.forward.z;
	new.forward.y = a.right.y * b.forward.x + a.up.x * b.forward.y + a.forward.y * b.forward.z;
	new.forward.z = a.right.y * b.forward.x + a.up.x * b.forward.y + a.forward.z * b.forward.z;
	return (new);
}

t_quat	quat_norm(double w, double x, double y, double z)
{
	t_quat new;
	double	mag;

	// w = (w/2) * M_PI / 180;
	mag = sqrt(pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2));
	new.w = w / mag;
	new.x = x / mag;
	new.y = y / mag;
	new.z = z / mag;
	return (new);
}

t_quat	quat_new(double w, double x, double y, double z)
{
	t_quat new;

	new.w = w;
	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_quat	quat_local_rot(t_vec3d axis, double angle)
{
	t_quat	res;

	axis = vec_normalize(axis);
	res.w = cos(angle / 2);
	res.x = axis.x * sin(angle / 2);
	res.y = axis.y * sin(angle / 2);
	res.z = axis.z * sin(angle / 2);
	return (res);
}

// ! q1 * q2 != q2 * q1

t_quat	quat_mult(t_quat q1, t_quat q2)
{
	t_quat res;
	res.w = ((q1.w * q2.w) - (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z));
	res.x = ((q1.w * q2.x) + (q1.x * q2.w) + (q1.y * q2.z) - (q1.z * q2.y));
	res.y = ((q1.w * q2.y) - (q1.x * q2.z) + (q1.y * q2.w) + (q1.z * q2.x));
	res.z = ((q1.w * q2.z) + (q1.x * q2.y) + (q1.y * q2.x) + (q1.z * q2.w));
	return (res);
}



t_matrix	quat_to_matrix(t_quat q)
{
	t_matrix res;

	res.right.x = 1 - 2 * pow(q.y, 2) - 2 * pow(q.z, 2);
	res.right.y = 2 * q.x * q.y - 2 * q.w * q.z;
	res.right.z = 2 * q.x * q.z + 2 * q.w * q.y;
	res.up.x = 2 * q.x * q.y + 2 * q.w * q.z;
	res.up.y = 1 - 2 * pow(q.x, 2) - 2 * pow(q.z, 2);
	res.up.z = 2 * q.y * q.z + 2 * q.w * q.x;
	res.forward.x = 2 * q.x * q.z - 2 * q.w * q.y;
	res.forward.y = 2 * q.y * q.z - 2 * q.w * q.x;
	res.forward.z = pow(q.w, 2) - pow(q.x, 2) - pow(q.y, 2) + pow(q.z, 2);

	return (res);
}

t_quat rotate_cam_right(t_vec3d vector, t_vec3d axis, double angle)
{
	t_quat	p;
	t_quat	p2;
	t_quat	r;
	t_quat	r2;

	p = quat_new(0, vector.x, vector.y, vector.z);
	r = quat_local_rot(axis, angle);
	r2 = quat_new(r.w, -r.x, -r.y, -r.z);
	p2 = quat_mult(quat_mult(r, p), r2);
	return (p2);
}