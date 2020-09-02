/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:11:09 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/08 14:42:12 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_mover(unsigned char *res, const unsigned char *str, size_t len)
{
	size_t i;

	if (res < str)
	{
		i = 0;
		while (i < len)
		{
			res[i] = str[i];
			i++;
		}
	}
	else if (res > str)
	{
		i = len;
		while (i > 0)
		{
			res[i - 1] = str[i - 1];
			i--;
		}
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*res;
	const unsigned char	*str;

	if (!(src) && !(dst))
		return ((void*)0);
	res = dst;
	str = src;
	ft_mover(res, str, len);
	return (dst);
}
