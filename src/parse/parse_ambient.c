/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:15:45 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:15:45 by vtenneke      ########   odam.nl         */
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

void	parse_ambient(char **info, t_data *data)
{
	if (data->mapinfo.amb_set == true)
		print_error("Ambient light can only be specified once", data);
	if (char_arrlen(info) != 3)
		print_error("Invalid amount of values given for ambient light", data);
	data->mapinfo.amb_ratio = parse_double(info[1]);
	data->mapinfo.amb_color = parse_color(info[2], data);
	if (data->mapinfo.amb_ratio > 1 || data->mapinfo.amb_ratio < 0)
		print_error("Invalid value given for ambient light", data);
	data->mapinfo.amb_set = true;
}
