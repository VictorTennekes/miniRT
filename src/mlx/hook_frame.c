/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:06:24 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/17 15:06:24 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <mlx.h>
#include <stdio.h>

int		hook_frame(t_data *data)
{
	uint16_t	i;
	uint16_t	j;
	t_vec2ui	pix;

	i = 0;
	while (i < data->window.x)
	{
		j = 0;
		pix.x = i;
		while (j < data->window.y)
		{
			pix.y = j;
			pixel_put(data->mlx_info.mlx_data, i, j, get_pixel(pix, data));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_info.mlx, data->mlx_info.mlx_win, data->mlx_info.mlx_data.img, 0, 0);
	return (0);
}