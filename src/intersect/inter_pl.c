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
	double	denom;
	double	t;

	(void)data;
	denom = vec_dot_prod(plane->vector, ray.direction);

	if (denom < 1e-6)
	{
		t = vec_dot_prod(vec_sub(plane->pos, ray.origin), plane->vector) / denom;
		if (t >= 0.0)
			return (true);
	}
	return (false);
}