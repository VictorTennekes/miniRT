/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_distance_points.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 11:16:57 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/07 15:56:12 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

#include <stdio.h>

double	calc_distance_points(t_coord *pos1, t_coord *pos2)
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