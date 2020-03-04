/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_mix.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 22:34:54 by victor         #+#    #+#                */
/*   Updated: 2020/02/18 22:34:54 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mix two colors by taking the avarage.
**
**	@param	:	{t_color} color_1
**	@param	:	{t_color} color_2
**
**	@return	:	{t_color}
*/

#include <minirt.h>

t_color	color_mix(t_color color_1, t_color color_2)
{
	return (color_new((color_1.r + color_2.r) / 2,
					(color_1.g + color_2.g) / 2,
					(color_1.b + color_2.b) / 2));
}
