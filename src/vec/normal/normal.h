/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 11:01:51 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/20 11:01:51 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Dispatching the ray_res normal function for appropriate object.
**
**	@param	:	{t_ray_res} ray_res
**	@param	:	{t_data *} data
**
**	@return	:	{t_vec3d}
*/

#ifndef NORMAL_H
# define NORMAL_H

# include <minirt.h>

t_vec3d	norm_pl(t_ray_res ray_res, t_ray ray, t_data *data);
t_vec3d	norm_sp(t_ray_res ray_res, t_ray ray, t_data *data);
t_vec3d	norm_tr(t_ray_res ray_res, t_ray ray, t_data *data);
t_vec3d norm_cy(t_ray_res ray_res, t_ray ray, t_data *data);
t_vec3d norm_ds(t_ray_res ray_res, t_ray ray, t_data *data);

typedef t_vec3d		(*t_normal_func)(t_ray_res ray_res,
	t_ray ray, t_data *data);

#endif
