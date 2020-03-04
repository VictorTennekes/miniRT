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

/*
**	Calculate the new position of the camera position or calculate the
**	direction of the orientation vector.
**
**	@param	:	{int} keycode
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include "key_codes.h"

#define CAM data->current_cam

void	cam_move(int keycode, t_data *data)
{
	data->window.rendered = false;
	if (keycode == KEY_A)
		CAM->pos = vec_sub(CAM->pos, vec_multi(CAM->matrix.right, MOVE_SPEED));
	else if (keycode == KEY_D)
		CAM->pos = vec_add(CAM->pos, vec_multi(CAM->matrix.right, MOVE_SPEED));
	else if (keycode == KEY_W)
		CAM->pos = vec_sub(CAM->pos, vec_multi(CAM->matrix.forward, MOVE_SPEED));
	else if (keycode == KEY_S)
		CAM->pos = vec_add(CAM->pos, vec_multi(CAM->matrix.forward, MOVE_SPEED));
	else if (keycode == KEY_LSHIFT)
		CAM->pos = vec_sub(CAM->pos, vec_multi(CAM->matrix.up, MOVE_SPEED));
	else if (keycode == KEY_SPACE)
		CAM->pos = vec_add(CAM->pos, vec_multi(CAM->matrix.up, MOVE_SPEED));
	else
		data->window.rendered = true;
}

void	cam_rotate(int keycode, t_data *data)
{
	data->window.rendered = false;
	if (keycode == KEY_LEFT)
	{
		CAM->quat = rotate_cam(CAM->matrix.forward, CAM->matrix.up, 5 * M_PI / 180);
		CAM->vector = vec_new(CAM->quat.x, CAM->quat.y, CAM->quat.z);
		CAM->vector = vec_multi(CAM->vector, -1);
		CAM->matrix = matrix_new(CAM->vector);
		CAM->matrix = normal_matrix(CAM->matrix);
	}
	else if (keycode == KEY_RIGHT)
	{
		CAM->quat = rotate_cam(CAM->matrix.forward, CAM->matrix.up, -5 * M_PI / 180);
		CAM->vector = vec_new(CAM->quat.x, CAM->quat.y, CAM->quat.z);
		CAM->vector = vec_multi(CAM->vector, -1);
		CAM->matrix = matrix_new(CAM->vector);
		CAM->matrix = normal_matrix(CAM->matrix);
	}
	else if (keycode == KEY_UP)
	{
		CAM->quat = rotate_cam(CAM->matrix.forward, CAM->matrix.right, 5 * M_PI / 180);
		CAM->vector = vec_new(CAM->quat.x, CAM->quat.y, CAM->quat.z);
		CAM->vector = vec_multi(CAM->vector, -1);
		CAM->matrix = matrix_new(CAM->vector);
	}
	else if (keycode == KEY_DOWN)
	{
		CAM->quat = rotate_cam(CAM->matrix.forward, CAM->matrix.right, -5 * M_PI / 180);
		CAM->vector = vec_new(CAM->quat.x, CAM->quat.y, CAM->quat.z);
		CAM->vector = vec_multi(CAM->vector, -1);
		CAM->matrix = matrix_new(CAM->vector);
	}
	else
		data->window.rendered = true;
}