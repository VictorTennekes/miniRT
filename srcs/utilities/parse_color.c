/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 17:09:09 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/29 17:53:42 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>
#include <stdlib.h>

t_color		parse_color(char *str)
{
	t_color	color;
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(str, ',');
	if (!isdigit_str(rgb[0]) || !isdigit_str(rgb[1]) || !isdigit_str(rgb[2]))
		print_error("Invalid color value.");
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r > 255 || r < 0)
		print_error("Invalid red color value.");
	if (g > 255 || g < 0)
		print_error("Invalid green color value.");
	if (b > 255 || b < 0)
		print_error("Invalid blue color value.");
	color.r = r;
	color.g = g;
	color.b = b;
	free(rgb);
	return (color);
}