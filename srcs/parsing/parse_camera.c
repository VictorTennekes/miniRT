/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 11:04:38 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/30 12:45:39 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>

void	parse_camera(char **info, t_data *data)
{
	t_camera camera;
	
	if (char_arrlen(info) != 4)
		print_error("Wrong number of values given for camera");
	camera.pos = parse_coord(info[1]);
}