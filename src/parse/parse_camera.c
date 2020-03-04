/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 11:04:38 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/04 09:47:30 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Parse info into the appropriate struct.
**
**	@param	:	{char **} infos
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <libft.h>
#include <liblist.h>
#include <stdlib.h>

t_matrix matrix_new(t_vec3d f)
{
	t_matrix	matrix;

	matrix.forward = vec_multi(f, -1);
	matrix.right = vec_cross_prod(vec_normalize(vec_new(0, 1, 0)),
					matrix.forward);
	matrix.up = vec_cross_prod(matrix.forward, matrix.right);
	normal_matrix(matrix);
	return (matrix);
}

void	parse_camera(char **info, t_data *data)
{
	t_camera *camera;
	
	if (char_arrlen(info) != 4)
		print_error("Invalid amount of values given for camera", data);
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		print_error("Malloc failed for camera", data);
	camera->pos = parse_coord(info[1]);
	camera->vector = parse_coord(info[2]);
	if ((camera->vector.x > 1 || camera->vector.x < -1) ||
		(camera->vector.y > 1 || camera->vector.y < -1) ||
		(camera->vector.z > 1 || camera->vector.z < -1))
		print_error("Invalid orientation vector given for camera", data);
	camera->vector = vec_normalize(camera->vector);
	camera->fov	= ft_atoi(info[3]);
	camera->quat = quat_new(1, 0, 0, 0);
	camera->matrix = matrix_new(camera->vector);
	if (camera->fov < 0 || camera->fov > 180)
		print_error("Invalid value given for FOV", data);
	if (!lst_new_back(&(data->cameras), camera))
		print_error("Allocation failed for camera", data);
}