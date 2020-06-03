/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx_img.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 10:02:43 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/12 10:02:43 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Initiate the mlx image by assigning the data from the data struct.
**
**	@param	:	{t_data *} data
**
**	@return	:	{bool}
*/

#include <minirt.h>
#include <mlx.h>

bool	init_mlx_img(t_data *data)
{
	data->mlx_info.mlx_data.img = mlx_new_image(data->mlx_info.mlx,
					data->window.x, data->window.y);
	if (!data->mlx_info.mlx_data.img)
		return (true);
	data->mlx_info.mlx_data.addr =
					mlx_get_data_addr(data->mlx_info.mlx_data.img,
					&data->mlx_info.mlx_data.bits_per_pixel,
					&data->mlx_info.mlx_data.line_length,
					&data->mlx_info.mlx_data.endian);
	if (!data->mlx_info.mlx_data.addr)
		return (true);
	return (false);
}
