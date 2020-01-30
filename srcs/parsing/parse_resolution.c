/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 12:03:43 by victor         #+#    #+#                */
/*   Updated: 2020/01/30 09:35:30 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdbool.h>
#include <libft.h>

void	parse_resolution(char **info, t_data *data)
{
	if (data->window.res_set == true)
		print_error("Multiple resolution specifications.");
	if (char_arrlen(info) != 3)
		print_error("Wrong number of values given for resolution.");
	if (!isdigit_str(info[1]) || !isdigit_str(info[2]))
		print_error("Invalid resolution value(s).");
	data->window.x = ft_atoi(info[1]);
	data->window.y = ft_atoi(info[2]);
	if (!data->window.x || !data->window.y)
		print_error("Invalid resolution.");
	data->window.res_set = true;
}