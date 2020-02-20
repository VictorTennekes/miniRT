/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 11:08:39 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/20 11:08:39 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "normal.h"

t_vec3d normal(t_ray_res ray_res, t_data *data)
{
	return(g_normal[ray_res.object->type](ray_res, data));
}