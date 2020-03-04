/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 18:34:46 by victor         #+#    #+#                */
/*   Updated: 2020/02/19 18:34:46 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Utilize the jumptable to calculate if a ray and object intersect.
**
**	@param	:	{t_object *} object
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{bool}
*/

#include <minirt.h>
#include "intersect.h"

bool	intersect(t_object *object, t_ray ray, t_data *data)
{
	return (g_intersect[object->type](object, ray, data));
}
