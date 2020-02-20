/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersec.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 18:29:40 by victor         #+#    #+#                */
/*   Updated: 2020/02/19 18:29:40 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H
# include <minirt.h>

bool	intersect_pl(t_object *plane, t_ray ray, t_data *data);
bool	intersect_sp(t_object *object, t_ray ray, t_data *data);

bool	(*g_intersect[])(t_object *, t_ray, t_data *) = {
	&intersect_pl,
	&intersect_sp,
	NULL,
	NULL,
	NULL
};

#endif