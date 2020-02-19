/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cast_ray.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 21:58:51 by victor         #+#    #+#                */
/*   Updated: 2020/02/11 14:16:52 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

t_color cast_ray(t_ray ray, t_data *data)
{
	t_ray_res ray_res;

	ray_res = cast_ray_object(ray, data);
	if (ray_res.distance == INFINITY)
		return(color_new(0,0,0));
	return (cast_all_light(ray_res, ray, data));
	return(ray_res.object->color);
}