/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_res_inf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 13:10:57 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/12 13:10:57 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Creating a s_ray_res struct that points to infinity.
**
**	@param	:	{void}
**
**	@return	:	{t_ray_res}
*/

#include <minirt.h>

t_ray_res	ray_res_inf(void)
{
	return (ray_res_dist_new(NULL, vec_new(0, 0, 0), color_new(0, 0, 0), \
		INFINITY));
}
