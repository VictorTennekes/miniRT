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

#define WINDOW data->window

t_matrix		look_at(t_camera  *camera, t_vec3d ray)
{
	t_matrix	res;
	
	(void)ray;
	res.forward = camera->vector;
	res.right = vec_cross_prod(vec_normalize(vec_new(0, 1, 0)), res.forward);
	res.up = vec_cross_prod(res.forward, res.right);
	res.from = camera->pos;
	return(res);
}

t_color		get_pixel(t_vec2ui pixel, t_data *data)
{
	t_ray		ray;
	t_camera	*camera;
	double		fov_fact;

	camera = data->current_cam;
	fov_fact = tan(camera->fov / 2 * (M_PI / 180));
	ray.origin.x = (2 * ((pixel.x + 0.5) / WINDOW.x) - 1) * fov_fact;
	ray.origin.y = (1 - (2 * ((pixel.y + 0.5) / WINDOW.y))) * fov_fact;
	ray.origin.z = 1;
	camera->matrix = look_at(camera, ray.origin);
	// ray.origin = look_at(camera, ray.origin);
	ray.origin = vec_add(ray.origin, camera->pos);
	if (WINDOW.x > WINDOW.y)
		ray.origin.x *= WINDOW.x / (double)WINDOW.y;
	else
		ray.origin.y *= WINDOW.y / (double)WINDOW.x;
	ray.direction = vec_a_to_b(camera->pos, ray.origin);
	return(cast_ray(ray, data));
} 