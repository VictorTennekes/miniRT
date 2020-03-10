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
**	@return	:	{double}
*/

#include <minirt.h>

static inline void	swap(double *d1, double *d2)
{
	double tmp;

	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}

double intersect_sp(t_object *sphere, t_ray ray, t_data *data)
{
	t_vec3d	p;
	double	t[3];
	double	tc[2];
	double	d2;

	(void)data;
	p = vec_sub(sphere->pos[0], ray.origin);
	tc[0] = vec_dot_prod(p, ray.direction);
	d2 = vec_dot_prod(p, p) - pow(tc[0], 2);
	if (d2 > sphere->size / 2)
		return (INFINITY);
	tc[1] = sqrt(sphere->size / 2 - d2);
	t[0] = tc[0] - tc[1];
	t[1] = tc[0] + tc[1];
	if (t[0] > t[1])
		swap(&t[0], &t[1]);
	if (t[0] < 0)
	{
		t[0] = t[1];
		if (t[0] < 0)
			return (INFINITY);
	}
	return (t[0]);
}