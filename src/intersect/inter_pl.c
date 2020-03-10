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

/*
**	Calculate if a ray and a plane intersect
**
**	@param	:	{t_object *} plane
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{double}
*/

#include <minirt.h>

double	intersect_pl(t_object *plane, t_ray ray, t_data *data)
{
	double	denom;
	double	t;

	(void)data;
	denom = vec_dot_prod(plane->vector, ray.direction);
	t = vec_dot_prod(vec_sub(plane->pos[0], ray.origin),
		plane->vector) / denom;
	if (t < 0 || double_compare(vec_dot_prod(ray.direction, plane->vector), 0))
		return (INFINITY);
	return (t);
}
