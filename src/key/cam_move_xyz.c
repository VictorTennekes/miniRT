/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cam_move_xyz.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:56:02 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/21 11:56:02 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include "key_codes.h"

#define CAM data->current_cam

void	cam_move(int keycode, t_data *data)
{
	data->window.rendered = false;
	if (keycode == KEY_A)
		CAM->pos.x -= vec_len(vec_multi(CAM->vector, MOVE_SPEED));
	else if (keycode == KEY_D)
		CAM->pos.x += vec_len(vec_multi(CAM->vector, MOVE_SPEED));
	else if (keycode == KEY_W)
		CAM->pos.z -= vec_len(vec_multi(CAM->vector, MOVE_SPEED));
	else if (keycode == KEY_S)
		CAM->pos.z += vec_len(vec_multi(CAM->vector, MOVE_SPEED));
	else if (keycode == KEY_LSHIFT)
		CAM->pos.y -= vec_len(vec_multi(CAM->vector, MOVE_SPEED));
	else if (keycode == KEY_SPACE)
		CAM->pos.y += vec_len(vec_multi(CAM->vector, MOVE_SPEED));
	else
		data->window.rendered = true;
}