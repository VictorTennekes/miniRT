/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lst_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:52:57 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/05 13:52:59 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"
#include <stdlib.h>

t_list	*lst_new(void *content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}
