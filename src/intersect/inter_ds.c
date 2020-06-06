/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter_ds.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 10:58:15 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/10 10:58:15 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculate if the ray and the disk intersect.
**
**	@param	:	{t_object *} disk
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{double}
*/

#include <minirt.h>

double	intersect_ds(t_object *disk, t_ray ray, t_data *data)
{
	double		t;
	t_vec3d		p;
	t_object	plane;

	plane.type = PL;
	plane.pos[0] = disk->pos[0];
	plane.vector = disk->vector;
	t = intersect(&plane, ray, data);
	if (t == INFINITY)
		return (INFINITY);
	p = vec_add(ray.origin, vec_multi(ray.direction, t));
	if (vec_dist(p, disk->pos[0]) > disk->size / 2)
		return (INFINITY);
	return (t);
}
