/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_light.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 15:12:18 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/06 13:28:25 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Parse info into the appropriate struct and linked list.
**
**	@param	:	{char **} infos
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <liblist.h>
#include <stdlib.h>

void	parse_light(char **info, t_data *data)
{
	t_light	*light;

	if (char_arrlen(info) != 4)
		print_error("Invalid amount of values given for light", data);
	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		print_error("Malloc failed for light", data);
	light->pos = parse_coord(info[1]);
	light->ratio = parse_double(info[2]);
	light->color = parse_color(info[3], data);
	if (light->ratio > 1 || light->ratio < 0)
		print_error("Invalid value given for light ratio", data);
	light->ratio *= 100;
	if (!lst_new_back(&(data->lights), light))
		print_error("Allocation failed for light", data);
}
