/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:15:01 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:15:01 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Dispatching the object intersection function for appropriate object.
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
double	intersect_ds(t_object *disk, t_ray ray, t_data *data);
double	intersect_cy(t_object *cylinder, t_ray ray, t_data *data);

double	(*g_intersect[])(t_object *, t_ray, t_data *) = {
	[PL] = &intersect_pl,
	[SP] = &intersect_sp,
	[CY] = &intersect_cy,
	[TR] = &intersect_tr,
	[DS] = &intersect_ds
};

#endif
