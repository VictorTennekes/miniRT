/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_square.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 10:51:27 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/06 13:26:53 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>
#include <mlx.h>

double	calc_square(t_object *object, t_data *data)
{
	t_camera	*camera;
	double		distance;
	double		cam_distance;

	camera = data->cameras->content;
	cam_distance = camera->distance;
	distance = calc_distance_points(&camera->pos, &object->pos);
	return (distance);
}