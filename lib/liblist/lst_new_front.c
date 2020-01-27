/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:23:30 by abe               #+#    #+#             */
/*   Updated: 2020/01/14 09:57:42 by abe              ###   ########.fr       */
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
