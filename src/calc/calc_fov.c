/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_fov.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:47:28 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/06 11:11:28 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

#include <stdio.h>

void	calc_fov(t_data *data)
{
	t_camera	*camera;
	double		camera_distance;
	double		fov_rad;

	camera = data->cameras->content;
	fov_rad = camera->fov * (M_PI / 180);
	camera_distance = ((data->window.x / 2) / (tan(fov_rad / 2)));
	camera->distance = camera_distance;
	printf("camera distance:	%f\n", camera_distance);
}