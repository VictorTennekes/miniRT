/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:00:09 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/20 13:00:09 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

void	free_list(t_list *list, void (*func)(void *))
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		func(list->content);
		free(list);
		list = tmp;
	}
}