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
