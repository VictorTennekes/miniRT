/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 11:01:51 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/20 11:01:51 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Redirecting the ray_res normal function for appropriate object.
**
**	@param	:	{t_ray_res} ray_res
**	@param	:	{t_data *} data
**
**	@return	:	{t_vec3d}
*/

#ifndef NORMAL_H
# define NORMAL_H

# include <minirt.h>

t_vec3d	norm_pl(t_ray_res ray_res, t_data *data);
t_vec3d	norm_sp(t_ray_res ray_res, t_data *data);
t_vec3d norm_cy(t_ray_res ray_res, t_data *data);

t_vec3d	(*g_normal[])(t_ray_res, t_data *) = {
	&norm_pl,	//TODO plane
	&norm_sp,	//TODO sphere
	NULL,	//TODO square
	&norm_cy,	//TODO cylinder
	NULL	//TODO  triangle
};

#endif