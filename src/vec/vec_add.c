/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_add.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 20:58:06 by victor         #+#    #+#                */
/*   Updated: 2020/02/10 21:25:33 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3d	vec_add(t_vec3d vec1, t_vec3d vec2)
{
	return (vec_new(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z));
}