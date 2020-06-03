/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:20:45 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/04 13:20:45 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Exit mlx by destroying the window and freeing the data struct.
**
**	@param	:	{int} keycode
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <mlx.h>

void	exit_mlx(int keycode, t_data *data)
{
	(void)keycode;
	mlx_destroy_window(data->mlx_info.mlx, data->mlx_info.mlx_win);
	exit_free(data);
}
