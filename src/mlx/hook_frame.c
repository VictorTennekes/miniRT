/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:06:24 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/17 15:06:24 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Loop over the window to make sure everything is rendered and is
**	re-rendered when updates take place. When multithreaded the frame is
**	rendered by multiple threads at the same time
**
**	@param	:	{t_data *} data
**
**	@return	:	{int}
*/

#include <minirt.h>
#include <mlx.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BONUS

t_color	*get_frame(t_data *data)
{
	t_color		*res;
	uint32_t	c[2];

	res = malloc(sizeof(t_color) * data->window.x * data->window.y);
	if (!res)
		print_error("Allocation failed for get_frame", data);
	c[0] = 0;
	while (c[0] < data->window.x)
	{
		c[1] = 0;
		while (c[1] < data->window.y)
		{
			res[c[0] * data->window.y + c[1]] = get_pixel((t_vec2ui){c[0], c[1]}, data);
			c[1]++;
		}
		c[0]++;
	}
	return (res);
}

#else

t_color	*get_frame(t_data *data)
{
	t_color			*color;
	pthread_t		threads[THREADS];
	int32_t			i;
	t_thread_data	*thread_data[THREADS];

	color = malloc(sizeof(t_color) * (data->window.x * data->window.y));
	if (!color)
		print_error("Malloc failed for get_frame", data);
	i = 0;
	while (i < THREADS)
	{
		thread_data[i] = thread_new(data, color, i);
		if (pthread_create(&threads[i], NULL, render_thread, thread_data[i]))
			print_error_free("Error creating thread", color, free, data);
		i++;
	}
	i--;
	while (i >= 0)
	{
		if ((pthread_join(threads[i], NULL)))
			print_error_free("Error creating thread", color, free, data);
		i--;
	}
	return (color);
}

#endif


int		hook_frame(t_data *data)
{
	t_color		*frame;
	uint16_t	c[2];

	if (data->window.rendered)
		return (0);
	data->window.rendered = true;
	frame = get_frame(data);
	c[0] = 0;
	while (c[0] < data->window.x)
	{
		c[1] = 0;
		while (c[1] < data->window.y)
		{
			pixel_put(data->mlx_info.mlx_data, c[0], c[1], frame[c[0] * data->window.y + c[1]]);
			c[1]++;
		}
		c[0]++;
	}
	mlx_put_image_to_window(data->mlx_info.mlx,
		data->mlx_info.mlx_win, data->mlx_info.mlx_data.img, 0, 0);
	return (0);
}
