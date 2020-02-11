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

#ifndef OBJ_DIST_H
# define OBJ_DIST_H

# include <minirt.h>

t_ray_res	(*g_object_dist_parse[])(t_object *, t_ray) = {
	NULL,	//TODO sphere
	NULL,	//TODO plane
	NULL,	//TODO square
	NULL,	//TODO cylinder
	NULL	//TODO  triangle
};

#endif