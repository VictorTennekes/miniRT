/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:06:24 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/08 14:42:12 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (!(tmp))
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
