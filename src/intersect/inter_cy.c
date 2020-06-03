/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter_cy.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:14:37 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:14:37 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

double		intersect_cy(t_object *cylinder, t_ray ray, t_data *data)
{
	t_vec3d p[2];
	t_vec3d	q;
	double	t[2];
	double	res;

	(void)data;
	p[0] = vec_sub(cylinder->pos[0],
		vec_multi(cylinder->vector, cylinder->height / 2.0));
	p[1] = vec_add(cylinder->pos[0],
		vec_multi(cylinder->vector, cylinder->height / 2.0));
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
		{
			if (res != -1.0)
				res = fmin(t[0], t[1]);
			else
				res = t[1];
		}
		if (res > 0.0)
			return (res);
	}
	return (INFINITY);
}
