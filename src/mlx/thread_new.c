/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 17:42:57 by victor        #+#    #+#                 */
/*   Updated: 2020/06/02 17:42:57 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

t_thread_data	*thread_new(t_data *data, t_color *color, uint32_t start)
{
	t_thread_data	*new;

	new = malloc(sizeof(t_thread_data));
	if (!new)
		print_error("Malloc failed for thread", data);
	new->data = data;
	new->color = color;
	new->start = start;
	return (new);
}