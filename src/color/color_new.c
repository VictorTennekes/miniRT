/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_new.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:13:52 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:13:52 by vtenneke      ########   odam.nl         */
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
