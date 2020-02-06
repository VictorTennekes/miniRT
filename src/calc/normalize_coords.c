/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize_coords.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 13:47:06 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/06 13:47:07 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// NDC Normalized Device Coordinates

t_coord	normalize_coords(t_coord coord, t_data *data)
{
	double pixelndc_x;
	double pixelndc_y;
	double pixelscreen_x;
	double pixelscreen_y;

	pixelndc_x = (coord.x + 0.5) / data->window.x;
	pixelndc_y = (coord.y + 0.5) / data->window.y;
	pixelscreen_x = 2 * pixelndc_x - 1;
	pixelscreen_y = 2 * pixelndc_y - 1;
	coord.x = pixelscreen_x;
	coord.y = pixelscreen_y;
	return (coord);
}