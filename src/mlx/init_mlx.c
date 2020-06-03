/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 10:02:27 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/12 10:02:27 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Initiate all the separate mlx components.
**
**	@param	:	{t_data *} data
**
**	@return	:	{bool}
*/

#include <minirt.h>
#include <mlx.h>

static int	exit_hook(t_data *data)
{
	exit_free(data);
	return (1);
}

bool		init_mlx(t_data *data)
{
	data->mlx_info.mlx = mlx_init();
	if (!data->mlx_info.mlx)
		return (true);
	data->mlx_info.mlx_win = mlx_new_window(data->mlx_info.mlx,
					data->window.x, data->window.y, "MiniRT");
	if (!data->mlx_info.mlx_win)
		return (true);
	if (init_mlx_img(data))
		return (true);
	mlx_hook(data->mlx_info.mlx_win, 17, 0L, &exit_hook, data);
	mlx_key_hook(data->mlx_info.mlx_win, &hook_key, data);
	mlx_loop_hook(data->mlx_info.mlx, &hook_frame, data);
	return (false);
}
