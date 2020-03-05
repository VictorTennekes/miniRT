/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double_compare.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 13:27:41 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/05 13:27:41 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	double_compare(double a, double b)
{
	double res;

	res = a - b;
	if (res < 0)
		res *= -1;
	return (res < EPSILON);
}