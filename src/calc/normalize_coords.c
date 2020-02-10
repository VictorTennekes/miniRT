/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize_coords.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 13:47:06 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/10 20:47:28 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// NDC Normalized Device Coordinates

t_vec3d	normalize_coords(t_vec3d coord, t_data *data)
{
	coord.x = 2 * ((coord.x + 0.5) / data->window.x) - 1;
	coord.y = 1 - 2 * ((coord.y + 0.5) / data->window.y);
	return (coord);
}