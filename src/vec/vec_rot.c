/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_rot.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/23 18:44:05 by victor         #+#    #+#                */
/*   Updated: 2020/02/23 18:44:05 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3d	vec_rot_y(t_vec3d vec, double factor)
{
	return(vec_new((vec.x * cos(factor)) + (vec.z * sin(factor)),
					vec.y,
					(-vec.x * sin(factor)) + (vec.z * cos(factor))));
}