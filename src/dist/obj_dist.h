/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_dist.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:14:21 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:14:21 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Dispatching the object distance function for appropriate object.
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
t_ray_res	obj_dist_cy(t_object *cylinder, t_ray ray, t_data *data);

typedef t_ray_res	(*t_dist_func)(t_object *obj, t_ray ray, t_data *data);

#endif
