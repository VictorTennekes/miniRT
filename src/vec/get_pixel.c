/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pixel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 20:57:29 by victor         #+#    #+#                */
/*   Updated: 2020/02/11 14:17:47 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

#define ORIGIN ray.origin
#define WINDOW data->window

t_color		get_pixel(t_vec2ui pixel, t_data *data)
{
	t_ray		ray;
	t_vec3d		camera_pos;
	t_camera	*camera;
	double		fov_fact;

	camera = data->cameras->content;
	fov_fact = tan(camera->fov / 2 * (M_PI / 180));
	camera_pos = camera->pos;
	ORIGIN.x = (2 * ((pixel.x + 0.5) / WINDOW.x) - 1) * fov_fact;
	ORIGIN.y = (1 - (2 * ((pixel.y + 0.5) / WINDOW.y))) * fov_fact;
	ORIGIN.z = -1;
	// TODO rotate origin according to camera angle
	ORIGIN = vec_add(ORIGIN, camera_pos);
	if (WINDOW.x > WINDOW.y)
		ORIGIN.x *= WINDOW.x / (double)WINDOW.y;
	else
		ORIGIN.y *= WINDOW.y / (double)WINDOW.x;
	ray.direction = vec_a_to_b(camera_pos, ORIGIN);
	return(cast_ray(ray, data));
} 