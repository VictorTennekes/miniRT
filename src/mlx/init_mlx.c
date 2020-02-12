/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 10:02:27 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/12 10:02:27 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <mlx.h>

bool	init_mlx(t_data *data)
{
	data->mlx_info.mlx = mlx_init();
	if (!data->mlx_info.mlx)
		return (true);
	data->mlx_info.mlx_win = mlx_new_window(data->mlx_info.mlx, data->window.x, \
		data->window.y, "MiniRT");
	if (!data->mlx_info.mlx_win)
		return (true);
	if (init_mlx_img(data))
		return (true);
	return (false);
}