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

#define MLX data->mlx_info.mlx

bool	init_mlx(t_data *data)
{
	MLX = mlx_init();
	if (!MLX)
		return (true);
	data->mlx_info.mlx_win = mlx_new_window(MLX,
					data->window.x, data->window.y, "MiniRT");
	if (!data->mlx_info.mlx_win)
		return (true);
	if (init_mlx_img(data))
		return (true);
	mlx_loop_hook(MLX, &hook_frame, data);
	return (false);
}