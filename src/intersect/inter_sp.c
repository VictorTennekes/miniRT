/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter_sp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 18:26:52 by victor         #+#    #+#                */
/*   Updated: 2020/02/19 18:26:52 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	intersect_sp(t_object *object, t_ray ray, t_data *data)
{
	double	t;
	t_vec3d	p;

	(void)data;
	t = vec_dot_prod(vec_sub(object->pos, ray.origin), ray.direction);
	if (t < 0)
		return (false);
	p = vec_add(ray.origin, vec_multi(ray.direction, t));
	if (vec_len(vec_sub(object->pos, p)) > object->size / 2)
		return (false);
	return (true);
}