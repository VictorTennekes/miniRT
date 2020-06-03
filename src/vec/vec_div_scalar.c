/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_div_scalar.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:19:11 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:19:11 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

inline t_vec3d	vec_div_scalar(t_vec3d vec, double scalar)
{
	return (vec_new(vec.x / scalar, vec.y / scalar, vec.z / scalar));
}
