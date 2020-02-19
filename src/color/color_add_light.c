/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_add_light.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 18:12:57 by victor         #+#    #+#                */
/*   Updated: 2020/02/19 18:12:57 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	color_add_light(t_color col1, t_color col2)
{
	return (color_new(fmax(col1.r, col2.r),
				fmax(col1.g, col2.g),
				fmax(col1.b, col2.b)));
}