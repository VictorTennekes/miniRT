/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 15:11:11 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/18 15:11:11 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	light(t_ray_res *ray_res, t_data *data)
{
	t_vec3d	norm;
	t_vec3d v;

	norm = norm_sp(ray_res->position, ray_res->object->pos);
	v = vec_multi(/*direction to p*/, -1);
}