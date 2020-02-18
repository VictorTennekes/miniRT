/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_multi.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 22:21:55 by victor         #+#    #+#                */
/*   Updated: 2020/02/18 22:21:55 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	color_multi(t_color color, double fact)
{
	return (color_new(fmin(color.r * fact, 255.0),
					fmin(color.g * fact, 255.0),
					fmin(color.b * fact, 255.0)));
}