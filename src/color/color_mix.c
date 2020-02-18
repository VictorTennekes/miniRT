/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_mix.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 22:34:54 by victor         #+#    #+#                */
/*   Updated: 2020/02/18 22:34:54 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	color_mix(t_color c1, t_color c2)
{
	return (color_new((c1.r + c2.r) / 2,
					(c1.g + c2.g) / 2,
					(c1.b + c2.b) / 2));
}