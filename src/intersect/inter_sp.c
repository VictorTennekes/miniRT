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

/*
**	Calculate if a ray and a sphere intersect
**
**	@param	:	{t_object *} sphere
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{bool}
*/

#include <minirt.h>

bool	intersect_sp(t_object *sphere, t_ray ray, t_data *data)
{
	double	t;
	t_vec3d	p;

	(void)data;
	t = vec_dot_prod(vec_sub(sphere->pos, ray.origin), ray.direction);
	if (t < 0)
		return (false);
	p = vec_add(ray.origin, vec_multi(ray.direction, t));
	if (vec_len(vec_sub(sphere->pos, p)) > sphere->size / 2)
		return (false);
	return (true);
}