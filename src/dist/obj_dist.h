/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_dist.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 13:26:25 by victor         #+#    #+#                */
/*   Updated: 2020/02/11 14:07:36 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Redirecting the object distance function for appropriate object.
**
**	@param	:	{t_object *} object
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{t_ray_res}
*/

#ifndef OBJ_DIST_H
# define OBJ_DIST_H

# include <minirt.h>

t_ray_res	obj_dist_pl(t_object *plane, t_ray ray, t_data *data);
t_ray_res	obj_dist_sp(t_object *sphere, t_ray ray, t_data *data);
t_ray_res	obj_dist_tr(t_object *triangle, t_ray ray, t_data *data);
t_ray_res	obj_dist_ds(t_object *disk, t_ray ray, t_data *data);

t_ray_res	(*g_object_dist_parse[])(t_object *, t_ray, t_data *) = {
	[PL] = &obj_dist_pl,
	[SP] = &obj_dist_sp,
	NULL,	//TODO square
	NULL,	//TODO cylinder
	[TR] = &obj_dist_tr,
	[DS] = &obj_dist_ds
};

#endif