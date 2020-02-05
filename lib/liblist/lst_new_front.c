/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_new_front.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:52:50 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/05 13:52:51 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
**	Add a new node to the start of a list.
**
**	@param {t_list **} node - a pointer to the first node of the list to add
**		the new node to. If this is NULL, nothing happens. If it points to NULL
**		a new list will be created and it's pointer will be stored in here.
**	@param {void *} content - the content of the new node
*/

void	lst_new_front(t_list **node, void *content)
{
	t_list	*new;

	if (!node)
		return ;
	if (!*node)
	{
		*node = lst_new(content);
		return ;
	}
	new = lst_new(content);
	new->next = *node;
	(*node)->prev = new;
	*node = new;
}
