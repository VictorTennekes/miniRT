/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_mix_light.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:13:32 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:13:32 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculate the color a colored surface will reflect when a color of light
**	falls on it.
**
**	@param	:	{t_color} color
**	@param	:	{t_color} light
**
**	@return	:	{t_color}
*/

#include <minirt.h>

t_color	color_mix_light(t_color color, t_color light)
{
	return (color_new(color.r * light.r / 255,
				color.g * light.g / 255,
				color.b * light.b / 255));
}
