/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_mix_light.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 23:00:09 by victor         #+#    #+#                */
/*   Updated: 2020/02/18 23:00:09 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	color_mix_light(t_color color, t_color light)
{
	return (color_new(color.r * light.r / 255,
				color.g * light.g / 255,
				color.b * light.b / 255));
}