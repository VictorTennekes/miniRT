/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_len.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 21:08:59 by victor         #+#    #+#                */
/*   Updated: 2020/02/10 21:10:16 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	vec_len(t_vec3d vec)
{
	return(sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}