/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quaternions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 13:50:09 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/28 13:50:09 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// w amount
// xyz axis

t_quat	quat_new(double x, double y, double z, double w)
{
	t_quate new;
	double	mag;

	w = (w/2) * M_PI / 180;
	mag = sqrt(pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2));
	new.w = w / mag;
	new.x = x / mag;
	new.y = y / mag;
	new.z = z / mag;
}