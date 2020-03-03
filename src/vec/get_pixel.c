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

t_vec3d		mult_vec_matrix(t_vec3d vec, t_matrix matrix)
{
	t_vec3d new;
	new.x = vec.x * matrix.right.x + vec.y * matrix.up.x + vec.z * matrix.forward.x;
	new.y = vec.x * matrix.right.y + vec.y * matrix.up.y + vec.z * matrix.forward.y;
	new.z = vec.x * matrix.right.z + vec.y * matrix.up.z + vec.z * matrix.forward.z;
	return (new);
}

t_vec3d		look_at(t_camera  *camera, t_vec3d ray)
{
	t_vec3d forward;
	t_vec3d	right;
	t_vec3d up;

	forward = vec_multi(camera->vector, -1);
	right = vec_cross_prod(vec_normalize(vec_new(0, 1, 0)), forward);
	up = vec_cross_prod(forward, right);
	t_matrix matrix;
	matrix.forward = forward;
	matrix.right = right;
	matrix.up = up;
	return(mult_vec_matrix(ray, matrix));
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
	ray.origin.z = -1;
	ray.origin = look_at(camera, ray.origin);
	if (WINDOW.x > WINDOW.y)
		ray.origin.x *= WINDOW.x / (double)WINDOW.y;
	else
		ray.origin.y *= WINDOW.y / (double)WINDOW.x;
	ray.direction = vec_normalize(ray.origin);
	ray.origin = data->current_cam->pos;
	// printf("RAY DIRECTION\nx: %f\ny: %f\nz: %f\n", ray.direction.x, ray.direction.y, ray.direction.z);
	return(cast_ray(ray, data));
} 