/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_coords.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 11:14:15 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/06 13:28:47 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <stdio.h>

t_coord		parse_coord(char *str)
{
	t_coord	coord;
	char	**values;

	values = ft_split(str, ',');
	coord.x = parse_double(values[0]);
	coord.y = parse_double(values[1]);
	coord.z = parse_double(values[2]);
	free_machine(values);
	return (coord);
}