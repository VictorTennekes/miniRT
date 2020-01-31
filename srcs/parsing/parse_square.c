/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_square.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 11:55:39 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/31 13:58:28 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <stdlib.h>
#include <liblist.h>

void	parse_square(char **info, t_data *data)
{
	t_object	*object;

	if (char_arrlen(info) != 5)
		print_error("Wrong value of arguments given for square");
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed in parse_square");
	object->type = SQ;
	object->pos = parse_coord(info[1]);
	object->vector = parse_coord(info[2]);
	object->size = parse_float(info[3]);
	object->color = parse_color(info[4]);
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed in parse_square");
}
