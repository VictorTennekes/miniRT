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

/*
**	Loop over the window to make sure everything is rendered and is
**	re-rendered when updates take place.
**
**	@param	:	{t_data *} data
**
**	@return	:	{int}
*/

#include <minirt.h>
#include <mlx.h>
#include <stdio.h>

int		hook_frame(t_data *data)
{
	uint16_t	c[2];
	t_vec2ui	pix;

	if (data->window.rendered)
		return (0);
	data->window.rendered = true;
	c[0] = 0;
	while (c[0] < data->window.x)
	{
		c[1] = 0;
		pix.x = c[0];
		while (c[1] < data->window.y)
		{
			pix.y = c[1];
			pixel_put(data->mlx_info.mlx_data, c[0], c[1], get_pixel(pix, data));
			c[1]++;
		}
		c[0]++;
	}
	mlx_put_image_to_window(data->mlx_info.mlx,
		data->mlx_info.mlx_win, data->mlx_info.mlx_data.img, 0, 0);
	return (0);
}
