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

t_vec3d		look_at(t_camera  *camera, t_vec3d ray)
{
	t_vec3d forward;
	t_vec3d	right;
	t_vec3d up;

	forward = camera->vector;
	right = vec_cross_prod(vec_normalize(vec_new(0, 1, 0)), forward);
	up = vec_cross_prod(forward, right);
	return (vec_new(right.x * ray.x + right.y *  ray.y + right.z * ray.z,
					up.x * ray.x + up.y * ray.y + up.z * ray.z,
					forward.x * ray.x + forward.y * ray.y + forward.z * ray.z));
}

t_color		get_pixel(t_vec2ui pixel, t_data *data)
{
	t_ray		ray;
	t_vec3d		camera_pos;
	t_camera	*camera;
	double		fov_fact;

	camera = data->current_cam;
	fov_fact = tan(camera->fov / 2 * (M_PI / 180));
	camera_pos = camera->pos;
	ORIGIN.x = (2 * ((pixel.x + 0.5) / WINDOW.x) - 1) * fov_fact;
	ORIGIN.y = (1 - (2 * ((pixel.y + 0.5) / WINDOW.y))) * fov_fact;
	ORIGIN.z = 1;
	ORIGIN = look_at(camera, ray.origin);
	ORIGIN = vec_add(ORIGIN, camera_pos);
	if (WINDOW.x > WINDOW.y)
		ORIGIN.x *= WINDOW.x / (double)WINDOW.y;
	else
		ORIGIN.y *= WINDOW.y / (double)WINDOW.x;
	ray.direction = vec_a_to_b(camera_pos, ORIGIN);
	return(cast_ray(ray, data));
} 