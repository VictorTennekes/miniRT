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

#include <minirt.h>
#include "intersec.h"

bool	intersect(t_object *obj, t_ray ray, t_data *data)
{
	return(g_intersect[obj->type](obj, ray, data));
}