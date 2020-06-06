/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cam_interact.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:56:02 by vtenneke      #+#    #+#                 */
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

void	cam_move(int keycode, t_data *data)
{
	data->window.rendered = false;
	if (keycode == KEY_A)
		data->current_cam->pos = vec_sub(data->current_cam->pos,
		vec_multi(data->current_cam->matrix.right, MOVE_SPEED));
	else if (keycode == KEY_D)
		data->current_cam->pos = vec_add(data->current_cam->pos,
		vec_multi(data->current_cam->matrix.right, MOVE_SPEED));
	else if (keycode == KEY_W)
		data->current_cam->pos = vec_sub(data->current_cam->pos,
		vec_multi(data->current_cam->matrix.forward, MOVE_SPEED));
	else if (keycode == KEY_S)
		data->current_cam->pos = vec_add(data->current_cam->pos,
		vec_multi(data->current_cam->matrix.forward, MOVE_SPEED));
	else if (keycode == KEY_LSHIFT)
		data->current_cam->pos = vec_sub(data->current_cam->pos,
		vec_multi(data->current_cam->matrix.up, MOVE_SPEED));
	else if (keycode == KEY_SPACE)
		data->current_cam->pos = vec_add(data->current_cam->pos,
		vec_multi(data->current_cam->matrix.up, MOVE_SPEED));
	else
		data->window.rendered = true;
}

void	cam_rotate_lr(int keycode, t_data *data)
{
	int	ratio;

	ratio = 0;
	data->window.rendered = false;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		ratio = keycode == KEY_LEFT ? 5 : -5;
		data->current_cam->quat = rotate_cam(data->current_cam->matrix.forward,
			data->current_cam->matrix.up, ratio * M_PI / 180);
		data->current_cam->vector = vec_new(data->current_cam->quat.x,
			data->current_cam->quat.y, data->current_cam->quat.z);
		data->current_cam->vector = vec_multi(data->current_cam->vector, -1);
		data->current_cam->matrix = matrix_new(data->current_cam->vector);
		data->current_cam->matrix = normal_matrix(data->current_cam->matrix);
	}
	else
		data->window.rendered = true;
}

void	cam_rotate_ud(int keycode, t_data *data)
{
	int ratio;

	ratio = 0;
	data->window.rendered = false;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		ratio = keycode == KEY_UP ? 5 : -5;
		data->current_cam->quat = rotate_cam(data->current_cam->matrix.forward,
			data->current_cam->matrix.right, ratio * M_PI / 180);
		data->current_cam->quat = quat_norm(data->current_cam->quat);
		data->current_cam->vector = vec_new(data->current_cam->quat.x,
			data->current_cam->quat.y, data->current_cam->quat.z);
		data->current_cam->vector = vec_multi(data->current_cam->vector, -1);
		data->current_cam->matrix = matrix_new(data->current_cam->vector);
		data->current_cam->matrix = normal_matrix(data->current_cam->matrix);
	}
	else
		data->window.rendered = true;
}
