/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_to_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:18:38 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/17 15:18:38 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	color_to_int(t_color color)
{
	return ((int)color.r << 16 | (int)color.g << 8 | (int)color.b);
}