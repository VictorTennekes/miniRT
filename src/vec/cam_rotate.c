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

// t_vec3d rotate_camera(t_vec3d point, t_vec3d vector, t_vec3d axis, double angle)
// {
// 	t_vec3d res;

// 	res.x = (axis.x * (pow(vector.y, 2) + pow(vector.z, 2)) - vector.x
// 			* ((axis.y * vector.y) + (axis.z * vector.z) - (vector.x * point.x)
// 			- (vector.y * point.y) - (vector.z * point.z)) * (1 - cos(angle))
// 			+ (point.x * cos(angle)) + ((-1 * (axis.z * vector.y))
// 			+ (axis.y * vector.z) - (vector.z * point.y) + (vector.y * point.z))
// 			* sin(angle));
// 	res.y = (axis.y  * (pow(vector.x, 2) + pow(vector.z, 2)) - vector.y
// 			* ((axis.x * vector.x) + (axis.z * vector.z) - (vector.x * point.x)
// 			- (vector.y * point.y) - (vector.z * point.z)) * (1 - cos(angle))
// 			+ (point.y * cos(angle)) + ((axis.z * vector.x) - (axis.x * vector.z)
// 			+ (vector.z * point.x) - (vector.x * point.z)) * sin(angle));
// 	res.z = (axis.z * (pow(vector.x, 2) + pow(vector.y, 2)) - vector.z
// 			* ((axis.x * vector.x) + (axis.y * vector.y) - (vector.x * point.x)
// 			- (vector.y * point.y) - (vector.z * point.z)) * (1 - cos(angle))
// 			+ (point.z * cos(angle)) + ((-1 * (axis.y * vector.x))
// 			+ (axis.x * vector.y) - (vector.y * point.x) + (vector.x * point.y))
// 			* sin(angle));
// 	return (res);
// }

// t_vec3d	rotate_cam(t_vec3d p, t_vec3d v, t_vec3d ax, double an)
// {
// 	t_vec3d res;
// 	double	l;

// 	v = vec_normalize(v);

// 	l = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
	
// 	res.x = ((ax.x * (pow(v.y, 2) + pow(v.z, 2)) - v.x * ((ax.y * v.y)
// 			+ (ax.z * v.z) - (v.x * p.x) - (v.y  * p.y) - (v.z * p.z)))
// 			* (1 - cos(an)) + l * p.x * cos(an) + sqrt(l) * ((-1 * ax.z * v.y)
// 			+ (ax.y * v.z) - (v.z * p.y) + (v.y * p.z)) * sin(an)) / l;
// 	res.y = ((ax.y * (pow(v.x, 2) + pow(v.z, 2)) - v.y * ((ax.x * v.x)
// 			+ (ax.z * v.z) - (v.x * p.x) - (v.y  * p.y) - (v.z * p.z)))
// 			* (1 - cos(an)) + l * p.y * cos(an) + sqrt(l) * ((ax.z * v.x)
// 			- (ax.x * v.z) + (v.z * p.x) + (v.x * p.y)) * sin(an)) / l;
// 	res.z = ((ax.z * (pow(v.x, 2) + pow(v.y, 2)) - v.z * ((ax.x * v.x)
// 			+ (ax.y * v.y) - (v.x * p.x) - (v.y * p.y) - (v.z * p.z)))
// 			* (1 - cos(an)) + l * p.z * cos(an) + sqrt(l) * ((-1 *  ax.y * v.x)
// 			+ (ax.x * v.x) - (v.y * p.x) + (v.x * p.y)) * sin(an)) / l;
// 	return (res);
// }