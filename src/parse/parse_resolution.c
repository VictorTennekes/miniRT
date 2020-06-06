/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:12:51 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:12:51 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Parse info into the appropriate struct.
**
**	@param	:	{char **} info
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <mlx.h>

void	parse_resolution(char **info, t_data *data)
{
	int screen[2];

	if (data->window.res_set == true)
		print_error("Resolution can only be specified once", data);
	if (char_arrlen(info) != 3)
		print_error("Invalid amount of values given for resolution", data);
	if (!isdigit_str(info[1]) || !isdigit_str(info[2]))
		print_error("Invalid value given for resolution", data);
	data->window.x = ft_atoi(info[1]);
	data->window.y = ft_atoi(info[2]);
	mlx_get_screen_size(data->mlx_info.mlx, &screen[0], &screen[1]);
	if (data->window.x > screen[0] && data->mapinfo.save != true)
		data->window.x = screen[0];
	if (data->window.y > screen[1] && data->mapinfo.save != true)
		data->window.y = screen[1];
	data->window.res_set = true;
}
