/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 16:55:45 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/30 17:03:43 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <liblist.h>
#include <stdlib.h>
#include <stdio.h>

void	parse_sphere(char **info, t_data *data)
{
	t_object *object;

	if (char_arrlen(info) != 4)
		print_error("Wrong number of values given for sphere.");
	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		print_error("Malloc failed in parse_sphere.");
	object->type = SP;
	object->pos = parse_coord(info[1]);
	object->size = parse_float(info[2]);
	object->color = parse_color(info[3]);
	if (!lst_new_back(&(data->objects), object))
		print_error("Allocation failed in parse_sphere");
}