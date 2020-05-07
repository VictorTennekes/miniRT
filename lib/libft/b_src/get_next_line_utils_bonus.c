/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:39 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/01/24 16:07:21 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <libft.h>
#include <errno.h>

int		ft_strrchr_gnl(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
		i++;
	if (!c)
		return (i);
	while (i >= 0)
	{
		if (s[i] == c)
			return (i);
		i--;
	}
	return (-1);
}

int		ft_strchr_gnl(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	if (!c)
		return (i);
	return (0);
}

char	*ft_gnl_substr(const char *s, unsigned int start, size_t len)
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
