/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_normalize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 14:04:40 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/10 20:47:28 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <math.h>

t_vec3d vec_normalize(t_vec3d vec)
{
	double len;

	len = vec_len(vec);
	return (vec_new(vec.x / len, vec.y / len, vec.z / len));
}