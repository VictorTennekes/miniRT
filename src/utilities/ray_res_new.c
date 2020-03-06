/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_res_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 11:21:36 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/12 11:21:36 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*
**	Creating a s_ray_res struct with given parameters.
**
**	@param	:	{t_object *} object
**	@param	:	{t_vec3d} vector
**	@param	:	{t_color} color
**
**	@return	:	{t_ray_res}
*/

t_ray_res	ray_res_new(t_object *object, t_vec3d vector, t_color color)
{
	return ((t_ray_res){.object = object, .position = vector, .color = color});
}

/*
**	Creating a s_ray_res struct with given parameters.
**
**	@param	:	{t_object *} object
**	@param	:	{t_vec3d} vector
**	@param	:	{t_color} color
**	@param	:	{double} distance
**
**	@return	:	{t_ray_res}
*/

t_ray_res	ray_res_dist_new(t_object *object, t_vec3d vector,
	t_color color, double distance)
{
	return ((t_ray_res){.object = object, .position = vector,
		.color = color, .distance = distance});
}
