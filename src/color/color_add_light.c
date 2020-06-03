/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_add_light.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:13:13 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:13:13 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Add color of light to color of a surface.
**	To simulate natural light the highest value will be preserved.
**
**	@param	:	{t_color} color_1
**	@param	:	{t_color} color_2
**
**	@return	:	{t_color}
*/

#include <minirt.h>

t_color	color_add_light(t_color color_1, t_color color_2)
{
	return (color_new(fmax(color_1.r, color_2.r),
				fmax(color_1.g, color_2.g),
				fmax(color_1.b, color_2.b)));
}
