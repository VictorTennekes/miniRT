/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_dist_sp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 11:14:52 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/12 11:14:52 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculate the distance between the ray origin and a sphere.
**
**	@param	:	{t_object *} sphere
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{t_ray_res}
*/

#include <minirt.h>

static inline void	swap(double *d1, double *d2)
{
	double tmp;

	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}

t_ray_res obj_dist_sp(t_object *sphere, t_ray ray, t_data *data)
{
	double	t[3];
	double	tc[2];
	double	d2;
	t_vec3d	p;

	(void)data;
	p = vec_sub(sphere->pos[0], ray.origin);
	tc[0] = vec_dot_prod(p, ray.direction);
	d2 = vec_dot_prod(p, p) - pow(tc[0], 2);
	if (d2 > sphere->size / 2)
		return (ray_res_inf());
	tc[1] = sqrt(sphere->size / 2 - d2);
	t[0] = tc[0] - tc[1];
	t[1] = tc[0] + tc[1];
	if (t[0] > t[1])
		swap(&t[0], &t[1]);
	if (t[0] < 0)
	{
		t[0] = t[1];
		if (t[0] < 0)
			return (ray_res_inf());
	}
	return (ray_res_dist_new(sphere, vec_add(ray.origin,
		vec_multi(ray.direction, t[0])), sphere->color, t[0]));
}
