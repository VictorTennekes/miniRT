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

/*
**	Utilize the jumptable to return the normal of a object retrieved
**	from ray_res.
**
**	@param	:	{t_ray_res} ray_res
**	@param	:	{t_data *} data
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>
#include "normal.h"

t_vec3d normal(t_ray_res ray_res, t_data *data)
{
	return(g_normal[ray_res.object->type](ray_res, data));
}