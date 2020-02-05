/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_new_back.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:52:44 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/05 13:52:46 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
**	Add a new node to the end of a list.
**
**	@param {t_list **} node - the address of the the first node of the list
**		to add the new node to. If this points to NULL, the pointer will be set
**		to the new node to create a new list. If this is NULL, nothing happens.
**	@param {void *} content - the content of the new node
**
**	@return {t_list *} - the pointer to the new node. NULL if something went
**		wrong.
*/

t_list	*lst_new_back(t_list **node, void *content)
{
	t_list	*new;
	t_list	*node_cpy;

	if (!node)
		return (NULL);
	if (!*node)
	{
		*node = lst_new(content);
		return (*node);
	}
	node_cpy = *node;
	while (node_cpy->next)
		node_cpy = node_cpy->next;
	new = lst_new(content);
	new->prev = node_cpy;
	node_cpy->next = new;
	return (new);
}
