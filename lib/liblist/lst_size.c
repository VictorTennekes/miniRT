/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_size.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:53:16 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/05 13:53:23 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

size_t	lst_size(t_list *node)
{
	size_t	res;

	res = 0;
	while (node)
	{
		node = node->next;
		res++;
	}
	return (res);
}
