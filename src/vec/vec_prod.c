/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_prod.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 10:45:51 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/27 10:45:51 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3d	vec_prod(t_vec3d vec1, t_vec3d vec2)
{
	t_vec3d res;

	res.x = vec1.x * vec2.x;
	res.y = vec1.y * vec2.y;
	res.z = vec1.z * vec2.z;
	return (res);
}