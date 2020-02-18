/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_distance_points.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 11:16:57 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/10 20:47:28 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	calc_distance_points(t_vec3d *pos1, t_vec3d *pos2)
{
	double	x;
	double	y;
	double	z;
	double	distance;

	x = pos1->x - pos2->x;
	y = pos1->y - pos2->y;
	z = pos1->z - pos2->z;
	distance = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return (distance);
}