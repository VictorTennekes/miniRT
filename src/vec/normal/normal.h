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

#ifndef NORMAL_H
# define NORMAL_H

# include <minirt.h>

t_vec3d	norm_sp(t_ray_res ray_res, t_data *data);

t_vec3d	(*g_normal[])(t_ray_res, t_data *) = {
	NULL,	//TODO plane
	&norm_sp,	//TODO sphere
	NULL,	//TODO square
	NULL,	//TODO cylinder
	NULL	//TODO  triangle
};

#endif