/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norm_pl.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 15:13:50 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/20 15:13:50 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3d	norm_pl(t_ray_res ray_res, t_data *data)
{
	(void)data;
	return(ray_res.object->vector);
}