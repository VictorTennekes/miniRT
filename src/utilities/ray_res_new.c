/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_res_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 11:21:36 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/12 11:21:36 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray_res 	ray_res_new(t_object *object, t_vec3d vector, t_color color)
{
	t_ray_res new;

	new.object = object;
	new.position = vector;
	new.color = color;
	return (new);
}

t_ray_res	ray_res_dist_new(t_object *object, t_vec3d vector, t_color color, \
	double distance)
{
	t_ray_res new;

	new.object = object;
	new.position = vector;
	new.color = color;
	new.distance = distance;
	return (new);
}