/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_foreach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abe <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:38:06 by abe               #+#    #+#             */
/*   Updated: 2020/01/14 09:57:10 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

/*
**	Execute a function for every node in a list.
**
**	@param {t_list *} node - the start of the list
**	@param {void (*)(void *)} func - a pointer to the function to call with
**		every nodes content as argument
*/

void	lst_foreach(t_list *node, void (*func)(void *))
{
	while (node)
	{
		func(node->content);
		node = node->next;
	}
}
