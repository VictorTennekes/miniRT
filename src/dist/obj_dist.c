/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_dist.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 14:07:15 by victor         #+#    #+#                */
/*   Updated: 2020/02/11 14:08:30 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Utilize the jumptable to calculate distance to the appropriate object.
**
**	@param	:	{t_object *} object
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{t_ray_res}
*/

#include <minirt.h>
#include "obj_dist.h"

t_ray_res	obj_dist(t_object *object, t_ray ray, t_data *data)
{
	return (g_object_dist_parse[object->type](object, ray, data));
}