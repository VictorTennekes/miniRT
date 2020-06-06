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

double	intersect(t_object *object, t_ray ray, t_data *data)
{
	return (g_intersect[object->type](object, ray, data));
}
