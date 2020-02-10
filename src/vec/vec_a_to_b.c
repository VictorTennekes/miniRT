/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_a_to_b.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 21:29:46 by victor         #+#    #+#                */
/*   Updated: 2020/02/10 21:29:48 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3d	vec_a_to_b(t_vec3d a, t_vec3d b)
{
	return (vec_normalize(vec_sub(b, a)));
}