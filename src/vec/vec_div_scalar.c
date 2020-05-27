/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_div_scalar.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 17:06:00 by victor        #+#    #+#                 */
/*   Updated: 2020/05/27 17:06:00 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

inline t_vec3d	vec_div_scalar(t_vec3d vec, double scalar)
{
	return (vec_new(vec.x / scalar, vec.y / scalar, vec.z / scalar));
}
