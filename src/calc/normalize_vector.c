/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize_vector.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:04:40 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/06 14:14:46 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

t_coord normalize_vector(t_coord coord)
{
	double length;

	length = sqrt(pow(coord.x, 2) + pow(coord.y, 2) + pow(coord.z, 2));
	coord.x = coord.x / length;
	coord.y = coord.y / length;
	coord.z = coord.z / length;
	return (coord);
}