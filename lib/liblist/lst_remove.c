/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_remove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:53:04 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/05 13:53:05 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"
#include <stdlib.h>

void	lst_remove(t_list *node, void (*free_func)(void *))
{
	if (!node)
		return ;
	free_func(node->content);
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
}
