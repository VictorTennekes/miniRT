/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_foreach.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:52:35 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/05 13:52:37 by vtenneke      ########   odam.nl         */
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
