/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_thread.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:15:21 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:15:21 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <pthread.h>
#include <stdlib.h>

void	*render_thread(void *param)
{
	t_thread_data	*thread_data;
	uint32_t		i;

	thread_data = param;
	i = thread_data->start;
	while (i < (thread_data->data->window.x * thread_data->data->window.y))
	{
		thread_data->color[i] =
			get_pixel((t_vec2ui){i / thread_data->data->window.y,
			i % thread_data->data->window.y}, thread_data->data);
		i += NCORES;
	}
	free(param);
	pthread_exit(NULL);
}