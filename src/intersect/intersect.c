/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:14:55 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:14:55 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Utilize the dispatcher to calculate if a ray and object intersect.
**
**	@param	:	{t_object *} object
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{double}
*/

#include <minirt.h>
#include "intersect.h"

static t_inter_func	obj_inter_dispatch(int type)
{
	static const	t_inter_func	inter_functions[] = {
		[PL] = &intersect_pl,
		[SP] = &intersect_sp,
		[CY] = &intersect_cy,
		[TR] = &intersect_tr,
		[DS] = &intersect_ds
	};

	return (inter_functions[type]);
}

double				intersect(t_object *object, t_ray ray, t_data *data)
{
	return (obj_inter_dispatch(object->type)(object, ray, data));
}
