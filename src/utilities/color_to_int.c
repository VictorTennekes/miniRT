/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_to_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:18:38 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/17 15:18:38 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Converting a s_color struct into a single int color value by
**	bitshifting the values.
**
**	@param	:	{t_color} color
**
**	@return	:	{int}
*/

#include <minirt.h>
#include <stdbool.h>

bool g_grey = false;

int	color_to_int(t_color color)
{
	if (g_grey == true)
		return ((int)((color.r + color.g + color.b) / 3) << 16 |
		(int)((color.r + color.g + color.b) / 3) << 8 |
		(int)((color.r + color.g + color.b) / 3));
	else
		return ((int)color.r << 16 | (int)color.g << 8 | (int)color.b);
}
