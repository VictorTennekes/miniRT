/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 12:59:49 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/20 12:59:49 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

void	free_data(t_data *data)
{
	if (data->objects)
		free_list(data->objects, &free);
	if (data->cameras)
		free_list(data->cameras, &free);
	if (data->lights)
		free_list(data->lights, &free);
}