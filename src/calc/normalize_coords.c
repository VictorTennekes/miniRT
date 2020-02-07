/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize_coords.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 13:47:06 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/07 13:29:41 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// NDC Normalized Device Coordinates

t_coord	normalize_coords(t_coord coord, t_data *data)
{
	coord.x = 2 * ((coord.x + 0.5) / data->window.x) - 1;
	coord.y = 2 * ((coord.y + 0.5) / data->window.y) - 1;
	return (coord);
}