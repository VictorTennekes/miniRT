/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust_normal.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 16:30:25 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/10 16:30:25 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Collection of functions to adjust a normal according to the ray direction
**	to fix weird lighting on both sides of an object.
*/

#include <minirt.h>

static double	vec_angle(t_vec3d vec1, t_vec3d vec2)
{
	double	res;
	
	res = vec_dot_prod(vec1, vec2);
	res /= vec_len(vec1) * vec_len(vec2);
	res = acos(res);
	return (res);
}

inline t_vec3d	adjust_normal(t_vec3d ray_dir, t_vec3d norm)
{
	if (vec_angle(norm, ray_dir) < M_PI_2)
		return (vec_multi(norm, -1));
	return (norm);
}