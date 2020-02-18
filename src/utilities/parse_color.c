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

#include <minirt.h>
#include <libft.h>
#include <stdlib.h>

t_color		parse_color(char *str)
{
	char	**rgb;
	double		r;
	double		g;
	double		b;

	rgb = ft_split(str, ',');
	if (!isdigit_str(rgb[0]) || !isdigit_str(rgb[1]) || !isdigit_str(rgb[2]))
		print_error("Invalid color value");
	r = parse_double(rgb[0]);
	g = parse_double(rgb[1]);
	b = parse_double(rgb[2]);
	if (r > 255 || r < 0)
		print_error("Invalid red color value");
	if (g > 255 || g < 0)
		print_error("Invalid green color value");
	if (b > 255 || b < 0)
		print_error("Invalid blue color value");
	free_machine(rgb);
	return (color_new(r, g, b));
}