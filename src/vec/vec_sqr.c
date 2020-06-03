/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_sqr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:19:37 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:19:37 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

inline double	vec_sqr(t_vec3d vec)
{
	return(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}