/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter_pl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 15:04:05 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/20 15:04:05 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	intersect_pl(t_object *plane, t_ray ray, t_data *data)
{
	double	t;

	(void)data;
	t = (vec_dot_prod(vec_sub(plane->pos, ray.origin), plane->vector) /
					vec_dot_prod(ray.direction, plane->vector));
	if (t < 0)
		return (false);
	return (true);
}