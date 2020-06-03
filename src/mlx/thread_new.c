/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thread_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:15:26 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:15:26 by vtenneke      ########   odam.nl         */
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