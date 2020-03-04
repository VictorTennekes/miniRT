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

/*
**	Check if the ray from a light to a object is obstructed by other objects.
**
**	@param	:	{t_object *} object
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{bool}
*/

bool	ray_obstructed(t_object *object, t_ray ray, t_data *data)
{
	t_list *objects;

	objects = data->objects;
	while (objects)
	{
		if (objects->content != object &&
				intersect((t_object *)objects->content, ray, data))
			return (true);
		objects = objects->next;
	}
	return (false);
}

/*
**	Calculate the effect of a light on the color of an object.
**
**	@param	:	{t_ray_res} ray_res
**	@param	:	{t_ray} ray
**	@param	:	{t_light *} light
**	@param	:	{t_data *} data
**
**	@return	:	{t_color}
*/

t_color	cast_light(t_ray_res ray_res, t_ray ray, t_light *light, t_data *data)
{
	t_vec3d	norm;
	t_vec3d	light_dir;
	double	fac;

	(void)data;
	(void)ray;
	if (ray_obstructed(ray_res.object, ray_new(ray_res.position,
		vec_a_to_b(ray_res.position, light->pos)), data))
		return (color_new(0, 0, 0));
	light_dir = vec_a_to_b(ray_res.position, light->pos);
	norm = normal(ray_res, data);
	fac = vec_dot_prod(light_dir, norm);
	if (fac < 0)
		return (color_new(0, 0, 0));
	fac *= light->ratio;
	fac /= 4 * M_PI * pow(vec_dist(light->pos, ray_res.position), 2);
	return (color_multi(color_mix_light(light->color, ray_res.object->color),
		fmin(fac, 1)));
}

/*
**	Cycle through the light to calculate which light have an effect
**	on the color of the object.
**
**	@param	:	{t_ray_res} ray_res
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{t_color}
*/

t_color	cast_all_light(t_ray_res ray_res, t_ray ray, t_data *data)
{
	t_color res;
	t_list	*lights;

	res = color_multi(data->mapinfo.amb_color, data->mapinfo.amb_ratio);
	res = color_mix_light(ray_res.object->color, res);
	lights = data->lights;
	while (lights)
	{
		res = color_add_light(res, cast_light(ray_res, ray,
			(t_light *)lights->content, data));
		lights = lights->next;
	}
	return (res);
}
