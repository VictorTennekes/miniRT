/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 11:04:38 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/30 14:50:11 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <liblist.h>
#include <stdlib.h>
#include <stdio.h>

void	parse_camera(char **info, t_data *data)
{
	t_camera *camera;
	
	if (char_arrlen(info) != 4)
		print_error("Wrong number of values given for camera");
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		print_error("Malloc failed in parse_camera.");
	camera->pos = parse_coord(info[1]);
	camera->vector = parse_coord(info[2]);
	camera->fov	= ft_atoi(info[3]);
	if (camera->fov < 0 || camera->fov > 180)
		print_error("Invalid value given for FOV.");
	if (!lst_new_back(&(data->cameras), camera))
		print_error("Allocation failed in parse_camera.");
}