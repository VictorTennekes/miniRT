/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_dist_ds.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:47:28 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/10 11:47:28 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculate the distance between the ray origin and a disk.
**
**	@param	:	{t_object *} disk
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{t_ray_res}
*/

#include <minirt.h>

t_ray_res	obj_dist_ds(t_object *disk, t_ray ray, t_data *data)
{
	t_ray_res	ds_plane;
	t_object	plane;

	plane.type = PL;
	plane.pos[0] = disk->pos[0];
	plane.vector = disk->vector;
	ds_plane = obj_dist(&plane, ray, data);
	if (ds_plane.distance == INFINITY)
		return (ray_res_inf());
	if (vec_dist(ds_plane.position, disk->pos[0]) > disk->size / 2)
		return (ray_res_inf());
	return (ray_res_dist_new(disk, ds_plane.position, disk->color,
		vec_dist(ray.origin, ds_plane.position)));
}
