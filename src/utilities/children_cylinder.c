/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   children_cylinder.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/07 13:39:55 by victor        #+#    #+#                 */
/*   Updated: 2020/05/07 13:39:55 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

void	init_cy_children(t_object *cylinder, t_data *data)
{
	t_object	*disk[2];

	(void)data;
	disk[0] = (t_object *)malloc(sizeof(t_object));
	disk[1] = (t_object *)malloc(sizeof(t_object));
	if (!disk[0] || !disk[1])
		print_error("Malloc failed for cylinder children", data);
	disk[0]->type = DS;
	disk[0]->pos[0] = vec_add(cylinder->pos[0], vec_multi(cylinder->vector, cylinder->height / 2));
	disk[0]->vector = cylinder->vector;
	disk[0]->size = cylinder->size;
	disk[0]->color = cylinder->color;
	disk[1]->type = DS;
	disk[1]->pos[0] = vec_sub(cylinder->pos[0], vec_multi(cylinder->vector, cylinder->height / 2));
	disk[1]->vector = cylinder->vector;
	disk[1]->size = cylinder->size;
	disk[1]->color = cylinder->color;
	if (!lst_new_back(&(data->objects), disk[0]) || !lst_new_back(&(data->objects), disk[1]))
		print_error("Allocation failed for cylinder children", data);
}