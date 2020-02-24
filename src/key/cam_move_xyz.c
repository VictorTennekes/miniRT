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
	// CAM->matrix = normal_matrix(CAM->matrix);
	data->window.rendered = false;
	if (keycode == KEY_A)
		CAM->pos = vec_sub(CAM->pos, vec_multi(CAM->matrix.right, MOVE_SPEED));
	else if (keycode == KEY_D)
		CAM->pos = vec_add(CAM->pos, vec_multi(CAM->matrix.right, MOVE_SPEED));
	else if (keycode == KEY_W)
		CAM->pos = vec_add(CAM->pos, vec_multi(CAM->matrix.forward, MOVE_SPEED));
	else if (keycode == KEY_S)
		CAM->pos = vec_sub(CAM->pos, vec_multi(CAM->matrix.forward, MOVE_SPEED));
	else if (keycode == KEY_LSHIFT)
		CAM->pos = vec_sub(CAM->pos, vec_multi(CAM->matrix.up, MOVE_SPEED));
	else if (keycode == KEY_SPACE)
		CAM->pos = vec_add(CAM->pos, vec_multi(CAM->matrix.up, MOVE_SPEED));
	else
		data->window.rendered = true;
	printf("CAM POS\nx:%f\ny:%f\nz:%f\n", CAM->pos.x, CAM->pos.y, CAM->pos.z);
	printf("CAM MATRIX\nforward_x: %f\nforward_y: %f\nforward_z: %f\n", CAM->matrix.forward.x, CAM->matrix.forward.y, CAM->matrix.forward.z);
	printf("right_x: %f\nright_y: %f\nright_z: %f\n", CAM->matrix.right.x, CAM->matrix.right.y, CAM->matrix.right.z);
	printf("up_x: %f\nup_y: %f\nup_z: %f\n", CAM->matrix.up.x, CAM->matrix.up.y, CAM->matrix.up.z);
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
