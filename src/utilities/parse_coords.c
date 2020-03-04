/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_coords.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 11:14:15 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/10 20:47:28 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdio.h>

t_vec3d		parse_coord(char *str)
{
	t_vec3d	coord;
	char	**values;

	values = ft_split(str, ',');
	coord.x = parse_double(values[0]);
	coord.y = parse_double(values[1]);
	coord.z = parse_double(values[2]);
	free_machine(values);
	return (coord);
}
