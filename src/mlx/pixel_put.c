/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_put.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:13:13 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/17 15:13:13 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Put a pixel into the mlx image on specific x y coordinates.
**
**	@param	:	{t_mlx_data} data
**	@param	:	{int} x
**	@param	:	{int} y
**	@param	:	{t_color} color
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <mlx.h>
#include <stdio.h>

void	pixel_put(t_mlx_data data, int x, int y, t_color color)
{
	char *dst;

	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*(unsigned int*)dst = color_to_int(color);
}
