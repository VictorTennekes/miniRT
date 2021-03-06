/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pixel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:18:45 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:18:45 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

/*
**	Rotating the orientation of the screen according to the orientation
**	vector of the used camera.
**
**	@param	:	{t_quat} quat
**
**	@return	:	{t_quat}
*/

t_vec3d		look_at(t_camera *camera, t_vec3d ray)
{
	t_matrix	matrix;
	t_vec3d		forward;
	t_vec3d		right;
	t_vec3d		up;

	forward = vec_multi(camera->vector, -1);
	right = vec_cross_prod(vec_normalize(vec_new(0, 1, 0)), forward);
	up = vec_cross_prod(forward, right);
	matrix.forward = forward;
	matrix.right = right;
	matrix.up = up;
	return (multi_vec_matrix(ray, matrix));
}

/*
**	Retrieving the location of a pixel on the screen according to the
**	resolution and the field of view. And passing to the cast ray function.
**
**	@param	:	{t_vec2ui} pixel
**	@param	:	{t_data *} data
**
**	@return	:	{t_color}
*/

t_color		get_pixel(t_vec2ui pixel, t_data *data)
{
	t_ray		ray;
	t_camera	*camera;
	double		fov_fact;

	camera = data->current_cam;
	fov_fact = tan(camera->fov / 2 * (M_PI / 180));
	ray.origin.x = (2 * ((pixel.x + 0.5) / data->window.x) - 1) * fov_fact;
	ray.origin.y = (1 - (2 * ((pixel.y + 0.5) / data->window.y))) * fov_fact;
	ray.origin.z = -1;
	ray.origin = look_at(camera, ray.origin);
	if (data->window.x > data->window.y)
		ray.origin.x *= data->window.x / (double)data->window.y;
	else
		ray.origin.y *= data->window.y / (double)data->window.x;
	ray.direction = vec_normalize(ray.origin);
	ray.origin = data->current_cam->pos;
	return (cast_ray(ray, data));
}
