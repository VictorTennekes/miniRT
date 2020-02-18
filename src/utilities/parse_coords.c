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
#include <libft.h>
#include <stdio.h>

t_vec3d		parse_coord(char *str)
{
	char	**values;

	values = ft_split(str, ',');
	free_machine(values);
	return (vec_new(parse_double(values[0]), parse_double(values[1]),
					parse_double(values[2])));
}