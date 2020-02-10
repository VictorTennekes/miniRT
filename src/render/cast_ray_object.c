/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cast_ray_object.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 22:01:47 by victor         #+#    #+#                */
/*   Updated: 2020/02/10 22:11:00 by victor        ########   odam.nl         */
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
		// TODO calculate closest object and save
	}
	// TODO if no closest return ray casting into infity
	// TODO else return closest ray
}