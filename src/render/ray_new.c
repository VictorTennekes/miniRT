/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 09:48:40 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/20 09:48:40 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray	ray_new(t_vec3d origin, t_vec3d direction)
{
	t_ray ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}