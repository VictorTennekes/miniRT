/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 23:01:37 by victor         #+#    #+#                */
/*   Updated: 2020/02/18 23:01:37 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	color_new(uint8_t r, uint8_t g, uint8_t b)
{
	t_color	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}