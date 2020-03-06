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

/*
**	Making a RGB color by placing the values inside of a s_color struct.
**
**	@param	:	{uint8_t} red
**	@param	:	{uint8_t} green
**	@param	:	{uint8_t} blue
**
**	@return	:	{t_color}
*/

#include <minirt.h>

t_color	color_new(uint8_t red, uint8_t green, uint8_t blue)
{
	return ((t_color){.r = red, .g = green, .b = blue});
}
