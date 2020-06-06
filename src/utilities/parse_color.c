/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 17:09:09 by vtenneke      #+#    #+#                 */
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
	double	c[3];

	rgb = ft_split(str, ',');
	if (char_arrlen(rgb) != 3)
		print_error("Invalid amount of color values", data);
	if (!isdigit_str(rgb[0]) || !isdigit_str(rgb[1]) || !isdigit_str(rgb[2]))
		print_error("Invalid color value", data);
	c[0] = parse_double(rgb[0]);
	c[1] = parse_double(rgb[1]);
	c[2] = parse_double(rgb[2]);
	if ((c[0] > 255 || c[0] < 0) ||
		(c[1] > 255 || c[1] < 0) ||
		(c[2] > 255 || c[2] < 0))
		print_error("Invalid color value", data);
	free_machine(rgb);
	return (color_new(c[0], c[1], c[2]));
}
