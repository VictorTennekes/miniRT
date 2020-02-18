/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx_img.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 10:02:43 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/12 10:02:43 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <mlx.h>

#define IMG data->mlx_info.mlx_data

bool	init_mlx_img(t_data *data)
{
	IMG.img = mlx_new_image(data->mlx_info.mlx,
					data->window.x, data->window.y);
	if (!IMG.img)
		return (true);
	IMG.addr = mlx_get_data_addr(IMG.img, &IMG.bits_per_pixel,
					&IMG.line_length, &IMG.endian);
	if (!IMG.addr)
		return (true);
	return (false);
}