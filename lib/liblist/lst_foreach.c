/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_foreach.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:52:35 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/05 13:52:37 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void	lst_foreach(t_list *node, void (*func)(void *))
{
	while (node)
	{
		func(node->content);
		node = node->next;
	}
}
