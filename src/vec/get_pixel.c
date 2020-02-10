/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pixel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 20:57:29 by victor         #+#    #+#                */
/*   Updated: 2020/02/10 21:14:20 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

t_color		get_pixel(t_vec2ui pixel, t_data *data)
{
	t_ray		ray;
	t_vec3d		camera_pos;
	t_camera	*camera;
	double		fov_fact;

	camera = data->cameras->content;
	fov_fact = camera->fov / 2 * (M_PI / 180);
	camera_pos = camera->pos;
	ray.origin.x = (2 * ((pixel.x + 0.5) / data->window.x) - 1) * fov_fact;
	ray.origin.y = (1 - (2 * ((pixel.y + 0.5) / data->window.y))) * fov_fact;
	ray.origin.z = -1;
	// TODO rotate origin according to camera angle
	ray.origin = vec_add(ray.origin, camera_pos);
	if (data->window.x > data->window.y)
		ray.origin.x *= data->window.x / (double)data->window.y;
	else
		ray.origin.y *= data->window.y / (double)data->window.x;
	ray.direction = 
} 