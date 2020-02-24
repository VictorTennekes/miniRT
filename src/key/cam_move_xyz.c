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
	double angle;

	angle = acos(vec_dot_prod(vec_normalize(CAM->vector), vec_new(0, 0, -1)));
	angle *= 180/M_PI;
	printf("angle: %f\n", angle);
	data->window.rendered = false;
	if (keycode == KEY_A)
		CAM->pos = vec_add(CAM->pos, vec_multi(vec_normalize(vec_rot_y(CAM->vector, -90 - (angle*2))), MOVE_SPEED));
	else if (keycode == KEY_D)
		CAM->pos = vec_add(CAM->pos, vec_multi(vec_normalize(vec_rot_y(CAM->vector, 90 - (angle*2))), MOVE_SPEED));
	else if (keycode == KEY_W)
		CAM->pos = vec_add(CAM->pos, vec_multi(vec_normalize(vec_rot_y(CAM->vector, 0 - (angle*2))), MOVE_SPEED));
	else if (keycode == KEY_S)
		CAM->pos = vec_add(CAM->pos, vec_multi(vec_normalize(vec_rot_y(CAM->vector, 180 - (angle*2))), MOVE_SPEED));
	else if (keycode == KEY_LSHIFT)
		CAM->pos.y -= vec_len(vec_multi(CAM->vector, MOVE_SPEED));
	else if (keycode == KEY_SPACE)
		CAM->pos.y += vec_len(vec_multi(CAM->vector, MOVE_SPEED));
	else
		data->window.rendered = true;
	printf("CAM POS\nx:%f\ny:%f\nz:%f\n", CAM->pos.x, CAM->pos.y, CAM->pos.z);
}

void	cam_rotate(int keycode, t_data *data)
{
	data->window.rendered = false;
	if (keycode == KEY_LEFT)
		CAM->vector = vec_rot_y(CAM->vector, (MOVE_SPEED * 5));
	else if (keycode == KEY_RIGHT)
		CAM->vector = vec_rot_y(CAM->vector, (-MOVE_SPEED * 5));
	else
		data->window.rendered = true;
}
