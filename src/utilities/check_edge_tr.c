/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_edge_tr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 11:54:10 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/05 11:54:10 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	check_edge_tr(t_object *triangle, t_vec3d normal, t_vec3d p)
{
	t_vec3d edge[3];
	t_vec3d c[3];

	edge[0] = vec_sub(triangle->pos[1], triangle->pos[0]);
	edge[1] = vec_sub(triangle->pos[2], triangle->pos[1]);
	edge[2] = vec_sub(triangle->pos[0], triangle->pos[2]);
	c[0] = vec_sub(p, triangle->pos[0]);
	c[1] = vec_sub(p, triangle->pos[1]);
	c[2] = vec_sub(p, triangle->pos[2]);
	return (vec_dot_prod(normal, vec_cross_prod(edge[0], c[0])) >= 0 &&
		vec_dot_prod(normal, vec_cross_prod(edge[1], c[1])) >= 0 &&
		vec_dot_prod(normal, vec_cross_prod(edge[2], c[2])) >= 0);
}
