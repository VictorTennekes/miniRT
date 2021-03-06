/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_dist_cy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:13:59 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:13:59 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Initialize all the values needed to check if the ray is hitting the object
**
**	@param	:	{t_object *} cylinder
**	@param	:	{t_ray} ray
**	@param	:	{double *} t
**
**	@return	:	{int}
*/

#include <minirt.h>
#include <math.h>

static int	init_cylinder_vars(t_object *cylinder, t_ray ray, double *t)
{
	double	abc[2];
	double	discr;
	t_vec3d	c[2];

	c[0] = vec_sub(ray.direction, vec_multi(cylinder->vector,
		vec_dot_prod(ray.direction, cylinder->vector)));
	c[1] = vec_sub(vec_sub(ray.origin, cylinder->pos[0]),
		vec_multi(cylinder->vector, vec_dot_prod(vec_sub(ray.origin,
		cylinder->pos[0]), cylinder->vector)));
	abc[0] = 2.0 * vec_dot_prod(c[0], c[1]);
	abc[1] = vec_sqr(c[1]) - pow(cylinder->size / 2, 2);
	discr = pow(abc[0], 2) - 4.0 * vec_sqr(c[0]) * abc[1];
	if (discr < 0.0)
		return (0);
	else if (discr < EPS)
	{
		t[0] = -0.5 * abc[0] / vec_sqr(c[0]);
		t[1] = t[0];
	}
	else
	{
		t[0] = (-abc[0] + sqrt(discr)) / (2.0 * vec_sqr(c[0]));
		t[1] = (-abc[0] - sqrt(discr)) / (2.0 * vec_sqr(c[0]));
	}
	return (1);
}

static void	init_values_cy(t_object *cylinder, t_vec3d *p)
{
	p[0] = vec_sub(cylinder->pos[0],
		vec_multi(cylinder->vector, cylinder->height / 2.0));
	p[1] = vec_add(cylinder->pos[0],
		vec_multi(cylinder->vector, cylinder->height / 2.0));
}

/*
**	Calculate the distance between the ray origin and a cylinder.
**
**	@param	:	{t_object *} cylinder
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{t_ray_res}
*/

t_ray_res	obj_dist_cy(t_object *cylinder, t_ray ray, t_data *data)
{
	t_vec3d p[2];
	t_vec3d	q;
	double	t[2];
	double	res;

	(void)data;
	init_values_cy(cylinder, p);
	res = -1.0;
	if (init_cylinder_vars(cylinder, ray, t) == 1)
	{
		q = vec_add(ray.origin, vec_multi(ray.direction, t[0]));
		if (t[0] > EPS && vec_dot_prod(cylinder->vector, vec_sub(q, p[0])) > 0.0
			&& vec_dot_prod(cylinder->vector, vec_sub(q, p[1])) < 0.0)
			res = t[0];
		q = vec_add(ray.origin, vec_multi(ray.direction, t[1]));
		if (t[1] > EPS && vec_dot_prod(cylinder->vector, vec_sub(q, p[0])) > 0.0
			&& vec_dot_prod(cylinder->vector, vec_sub(q, p[1])) < 0.0)
			res = (res != -1.0) ? fmin(t[0], t[1]) : t[1];
		if (res > 0.0)
			return (ray_res_dist_new(cylinder, vec_add(ray.origin,
			vec_multi(ray.direction, res)), cylinder->color, res));
	}
	return (ray_res_inf());
}
