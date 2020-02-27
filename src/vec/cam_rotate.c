/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cam_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:46:14 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/27 15:46:14 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3d rotate_camera(t_vec3d point, t_vec3d vector, t_vec3d axis, double angle)
{
	t_vec3d res;

	res.x = (axis.x * (pow(vector.y, 2) + pow(vector.z, 2)) - vector.x
			* ((axis.y * vector.y) + (axis.z * vector.z) - (vector.x * point.x)
			- (vector.y * point.y) - (vector.z * point.z)) * (1 - cos(angle))
			+ (point.x * cos(angle)) + ((-1 * (axis.z * vector.y))
			+ (axis.y * vector.z) - (vector.z * point.y) + (vector.y * point.z))
			* sin(angle));
	res.y = (axis.y  * (pow(vector.x, 2) + pow(vector.z, 2)) - vector.y
			* ((axis.x * vector.x) + (axis.z * vector.z) - (vector.x * point.x)
			- (vector.y * point.y) - (vector.z * point.z)) * (1 - cos(angle))
			+ (point.y * cos(angle)) + ((axis.z * vector.x) - (axis.x * vector.z)
			+ (vector.z * point.x) - (vector.x * point.z)) * sin(angle));
	res.z = (axis.z * (pow(vector.x, 2) + pow(vector.y, 2)) - vector.z
			* ((axis.x * vector.x) + (axis.y * vector.y) - (vector.x * point.x)
			- (vector.y * point.y) - (vector.z * point.z)) * (1 - cos(angle))
			+ (point.z * cos(angle)) + ((-1 * (axis.y * vector.x))
			+ (axis.x * vector.y) - (vector.y * point.x) + (vector.x * point.y))
			* sin(angle));
	return (res);
}