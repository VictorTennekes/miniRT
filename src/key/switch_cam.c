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

/*
**	Switch between camera's accessing previous or next nodes.
**
**	@param	:	{int} keycode
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <key_codes.h>
#include <stdlib.h>

void	switch_cam_next(int keycode, t_data *data)
{
	t_list		*cameras;

	(void)keycode;
	data->window.rendered = false;
	cameras = data->cameras;
	while (cameras->next)
	{
		if (cameras->content == data->current_cam)
			break ;
		cameras = cameras->next;
	}
	if (cameras->next)
		data->current_cam = cameras->next->content;
	else if (!cameras->next)
	{
		while (cameras->prev)
			cameras = cameras->prev;
		data->current_cam = cameras->content;
	}
}

void	switch_cam_prev(int keycode, t_data *data)
{
	t_list		*cameras;

	(void)keycode;
	data->window.rendered = false;
	cameras = data->cameras;
	while (cameras->next)
	{
		if (cameras->content == data->current_cam)
			break ;
		cameras = cameras->next;
	}
	if (cameras->prev)
		data->current_cam = cameras->prev->content;
	else if (!cameras->prev)
	{
		while (cameras->next)
			cameras = cameras->next;
		data->current_cam = cameras->content;
	}
}
