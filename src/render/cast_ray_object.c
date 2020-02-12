/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cast_ray_object.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 22:01:47 by victor         #+#    #+#                */
/*   Updated: 2020/02/11 14:14:49 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

t_ray_res	cast_ray_object(t_ray ray, t_data *data)
{
	t_list		*current_object;
	t_object	*closest_object;
	double		min_distance;
	t_ray_res	ray_res;
	t_ray_res	ray_res_closest;

	min_distance = INFINITY;
	closest_object = NULL;
	current_object = data->objects;
	while (current_object)
	{
		ray_res = obj_dist((t_object *)current_object, ray);
		if (ray_res.distance < min_distance)
		{
			closest_object = (t_object *)current_object->content;
			min_distance = ray_res.distance;
			ray_res_closest = ray_res;
		}
		current_object = current_object->next;
	}
	// TODO if no closest return ray casting into infity
	if (!closest_object)
		return (ray_res_inf());
	return (ray_res_closest);
}