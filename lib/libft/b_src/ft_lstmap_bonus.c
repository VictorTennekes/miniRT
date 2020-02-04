/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 09:19:45 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/08 14:42:12 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*res;
	t_list	*new;
	void	*content;

	if (!(lst))
		return (0);
	res = 0;
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(f(lst->content));
		if (!(new))
			ft_lstclear(&lst, del);
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
