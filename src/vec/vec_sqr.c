/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_sqr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/04 12:13:19 by victor        #+#    #+#                 */
/*   Updated: 2020/05/04 12:13:19 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

inline double	vec_sqr(t_vec3d vec)
{
	return(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}