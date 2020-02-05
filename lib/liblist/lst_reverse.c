/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_reverse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:53:09 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/05 13:53:11 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
**	Reverse a linked list.
**
**	@param {t_list **} node - a pointer to the start of the list. The pointer
**		to the new beginning of the list will be stored here.
*/

void	lst_reverse(t_list **node)
{
	t_list	*node_cpy;
	t_list	*tmp;

	if (!node)
		return ;
	if (!*node)
		return ;
	node_cpy = *node;
	tmp = NULL;
	while (node_cpy)
	{
		tmp = node_cpy->prev;
		node_cpy->prev = node_cpy->next;
		node_cpy->next = tmp;
		node_cpy = node_cpy->prev;
	}
	*node = tmp->prev;
}
