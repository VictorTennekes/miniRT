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
	t_vec3d vec;
	vec = vec_add(vec_new(1,0,0), vec_new(-1,0,-1));
	printf("test vec\nx: %f\ny: %f\nz: %f\n\n", vec.x, vec.y, vec.z);
	printf("CAM POS\nx:%f\ny:%f\nz:%f\n", CAM->pos.x, CAM->pos.y, CAM->pos.z);
	printf("CAM MATRIX\nforward_x: %f\nforward_y: %f\nforward_z: %f\n", CAM->matrix.forward.x, CAM->matrix.forward.y, CAM->matrix.forward.z);
	printf("right_x: %f\nright_y: %f\nright_z: %f\n", CAM->matrix.right.x, CAM->matrix.right.y, CAM->matrix.right.z);
	printf("up_x: %f\nup_y: %f\nup_z: %f\n", CAM->matrix.up.x, CAM->matrix.up.y, CAM->matrix.up.z);
}

t_vec3d rot_vec_right(t_vec3d vec, double angle)
{
	t_vec3d res;

	res.x = (vec.x * cos(angle)) + (vec.z * sin(angle));
	res.y = vec.y;
	res.z = (-1 * vec.x * sin(angle)) + (vec.z * cos(angle));
	return (res);
}

void	cam_rotate(int keycode, t_data *data)
{
	data->window.rendered = false;
	if (keycode == KEY_LEFT)
	{
		CAM->quat = rotate_cam_right(CAM->matrix.forward, CAM->matrix.up, 10 * M_PI / 180);
		CAM->vector = vec_new(CAM->quat.x, CAM->quat.y, CAM->quat.z);
		CAM->matrix = matrix_new(CAM->vector);
		printf("CAM MATRIX\nforward_x: %f\nforward_y: %f\nforward_z: %f\n", CAM->matrix.forward.x, CAM->matrix.forward.y, CAM->matrix.forward.z);
	}
	else if (keycode == KEY_RIGHT)
	{
	}
	else
		data->window.rendered = true;
}