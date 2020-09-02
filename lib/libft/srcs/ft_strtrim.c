/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 10:25:54 by vtenneke       #+#    #+#                */
/*   Updated: 2019/12/04 14:00:24 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	in_set(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*b;
	char	*e;

	if (s1 == 0)
		return (NULL);
	b = (char*)s1;
	e = (char*)s1 + ft_strlen(s1) - 1;
	while (in_set(set, *b))
		b++;
	while (e != s1 && in_set(set, *e))
		e--;
	e++;
	res = (char*)malloc((b >= e) ? 1 : (e - b + 1));
	if (res == NULL)
		return (NULL);
	if (b >= e)
		res[0] = '\0';
	else
		ft_strlcpy(res, b, e - b + 1);
	return (res);
}
