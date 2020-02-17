/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:06:24 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/17 15:06:24 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <mlx.h>

int		hook_frame(t_data *data)
{
	uint16_t	i;
	uint16_t	j;

	i = 0;
	while (i < data->window.x)
	{
		j = 0;
		while (j < data->window.y)
		{
			j++;
		}
		i++;
	}
	return (0);
}