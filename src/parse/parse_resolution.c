/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 12:03:43 by victor         #+#    #+#                */
/*   Updated: 2020/02/10 11:56:55 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Parse info into the appropriate struct.
**
**	@param	:	{char **} infos
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <mlx.h>

void	parse_resolution(char **info, t_data *data)
{
	int screen_x;
	int screen_y;
	
	if (data->window.res_set == true)
		print_error("Resolution can only be specified once", data);
	if (char_arrlen(info) != 3)
		print_error("Invalid amount of values given for resolution", data);
	if (!isdigit_str(info[1]) || !isdigit_str(info[2]))
		print_error("Invalid value given for resolution", data);
	data->window.x = ft_atoi(info[1]);
	data->window.y = ft_atoi(info[2]);
	mlx_get_screen_size(data->mlx_info.mlx, &screen_x, &screen_y);
	if (data->window.x > screen_x)
		data->window.x = screen_x;
	if (data->window.y > screen_y)
		data->window.y = screen_y;
	data->window.res_set = true;
}
