/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 11:08:39 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/20 11:08:39 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Utilize the dispatcher to return the normal of a object retrieved
**	from ray_res.
**
**	@param	:	{t_ray_res} ray_res
**	@param	:	{t_data *} data
**
**	@return	:	{t_vec3d}
*/

#include <minirt.h>
#include "normal.h"

static t_normal_func	normal_dispatch(int type)
{
	static const	t_normal_func	normal_functions[] = {
		[PL] = &norm_pl,
		[SP] = &norm_sp,
		[CY] = &norm_cy,
		[TR] = &norm_tr,
		[DS] = &norm_ds
	};

	return (normal_functions[type]);
}

t_vec3d					normal(t_ray_res ray_res, t_ray ray, t_data *data)
{
	return (normal_dispatch(ray_res.object->type)(ray_res, ray, data));
}
