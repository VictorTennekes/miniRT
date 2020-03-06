/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 18:29:40 by victor         #+#    #+#                */
/*   Updated: 2020/02/19 18:29:40 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Redirecting the object intersection function for appropriate object.
**
**	@param	:	{t_object *} object
**	@param	:	{t_ray} ray
**	@param	:	{t_data *} data
**
**	@return	:	{double}
*/

#ifndef INTERSECT_H
# define INTERSECT_H
# include <minirt.h>

double	intersect_pl(t_object *plane, t_ray ray, t_data *data);
double	intersect_sp(t_object *sphere, t_ray ray, t_data *data);
double	intersect_tr(t_object *triangle, t_ray ray, t_data *data);

double	(*g_intersect[])(t_object *, t_ray, t_data *) = {
	[PL] = &intersect_pl,
	[SP] = &intersect_sp,
	NULL,
	NULL,
	[TR] = &intersect_tr
};

#endif
