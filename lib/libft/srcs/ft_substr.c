/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 09:11:59 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/24 14:39:21 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (i < start)
		return (ft_strdup(""));
	res = (char*)malloc(sizeof(char) *
		((i - start < len) ? i - start : len) + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, ((i - start < len) ? i - start : len) + 1);
	return (res);
}
