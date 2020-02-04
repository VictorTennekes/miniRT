/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_fov.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 16:47:28 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/04 17:14:30 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

void	calc_fov(t_data *data)
{
	t_camera	*camera;
	double		camera_distance;

	camera = data->cameras->content;
	camera_distance = ((data->window.x / 2) / (tan(camera->fov / 2)));
}