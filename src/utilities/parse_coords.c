/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_coords.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 11:14:15 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/10 20:47:28 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Parsing the coordinate values and returning a s_vec3d struct.
**
**	@param	:	{char *} str
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>
#include <stdio.h>

t_vec3d		parse_coord(char *str, t_data *data)
{
	t_vec3d	coord;
	char	**values;

	values = ft_split(str, ',');
	if (char_arrlen(values) != 3)
		print_error("wrong amont of arguments given for xyz", data);
	coord.x = parse_double(values[0]);
	coord.y = parse_double(values[1]);
	coord.z = parse_double(values[2]);
	free_machine(values);
	return (coord);
}
