/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   switch_cam.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 13:20:50 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/03 14:36:15 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <key_codes.h>
#include <stdlib.h>

void switch_cam(int keycode, t_data *data)
{
	t_list		*cameras;

	data->window.rendered = false;
	cameras = data->cameras;
	while (cameras->next)
	{
		printf("loop");
		if (cameras->content == data->current_cam)
			break;
		cameras = cameras->next;
	}
	if (keycode == KEY_P)
	{
		if  (cameras->next)
			data->current_cam = cameras->next->content;
		else if (!cameras->next)
		{
			while (cameras->prev)
				cameras = cameras->prev;
			data->current_cam = cameras->content;
		}
	}
	else if (keycode == KEY_O)
	{
		if (cameras->prev)
			data->current_cam = cameras->prev->content;
		else if (!cameras->prev)
		{
			while (cameras->next)
				cameras = cameras->next;
			data->current_cam = cameras->content;
		}
	}
	else
		data->window.rendered = true;
	printf("pressed");
}
