/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_triangle.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 16:18:44 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/31 16:30:23 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <stdlib.h>
#include <liblist.h>

#include <stdio.h>

void	parse_triangle(char **info, t_data * data)
{
	t_object *object;

	if (char_arrlen(info) != 5)
		print_error("Wrong value of arguments given for cylinder");
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed in parse_triangle");
	object->type = TR;
	object->pos = parse_coord(info[1]);
	// object->pos2 = parse_coord(info[2]);
	// object->pos3 = parse_coord(info[3]);
	object->color = parse_color(info[4]);
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed in parse_triangle");
}