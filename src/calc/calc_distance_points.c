/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_distance_points.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 11:16:57 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/06 11:36:41 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

#include <stdio.h>

float	calc_distance_points(t_coord *pos1, t_coord *pos2)
{
	float	x;
	float	y;
	float	z;
	float	distance;

	x = pos1->x - pos2->x;
	y = pos1->y - pos2->y;
	z = pos1->z - pos2->z;
	printf("joined x: %f\n", x);
	printf("joined y: %f\n", y);
	printf("joined z: %f\n", z);
	distance = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return (distance);
}