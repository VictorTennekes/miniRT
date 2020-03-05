/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_in_out.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 11:54:10 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/05 11:54:10 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	check_edge_tr(t_object *triangle, t_vec3d p)
{
	t_vec3d c;

	c = (vec_cross_prod(vec_sub(triangle->pos2, triangle->pos),
		vec_sub(p, triangle->pos)));
	if (vec_dot_prod(triangle->vector, c) < 0)
		return (false);
	c = (vec_cross_prod(vec_sub(triangle->pos3, triangle->pos2),
		vec_sub(p, triangle->pos2)));
	if (vec_dot_prod(triangle->vector, c) < 0)
		return (false);
	c = (vec_cross_prod(vec_sub(triangle->pos, triangle->pos3),
		vec_sub(p, triangle->pos3)));
	if (vec_dot_prod(triangle->vector, c) < 0)
		return (false);
	return (true);
}