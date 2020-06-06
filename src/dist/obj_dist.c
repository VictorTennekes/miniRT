/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_dist.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:14:13 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:14:13 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Utilize the dispatcher to calculate distance to the appropriate object.
**
**	@param	:	{t_object *} object
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{t_ray_res}
*/

#include <minirt.h>
#include "obj_dist.h"

static t_dist_func	obj_dist_dispatch(int type)
{
	static const	t_dist_func	dist_functions[] = {
		[PL] = &obj_dist_pl,
		[SP] = &obj_dist_sp,
		[CY] = &obj_dist_cy,
		[TR] = &obj_dist_tr,
		[DS] = &obj_dist_ds
	};

	return (dist_functions[type]);
}

t_ray_res			obj_dist(t_object *object, t_ray ray, t_data *data)
{
	return (obj_dist_dispatch(object->type)(object, ray, data));
}
