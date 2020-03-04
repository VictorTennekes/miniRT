/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 17:09:09 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/07 13:31:26 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Parsing the color values and returning a s_color struct.
**
**	@param	:	{char *} str
**	@param	:	{t_data *} data
**
**	@return	:	{t_color}
*/

#include <minirt.h>
#include <stdlib.h>

t_color		parse_color(char *str, t_data *data)
{
	char	**rgb;
	double		r;
	double		g;
	double		b;

	rgb = ft_split(str, ',');
	if (!isdigit_str(rgb[0]) || !isdigit_str(rgb[1]) || !isdigit_str(rgb[2]))
		print_error("Invalid color value", data);
	r = parse_double(rgb[0]);
	g = parse_double(rgb[1]);
	b = parse_double(rgb[2]);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		print_error("Invalid color value", data);
	free_machine(rgb);
	return (color_new(r, g, b));
}