/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 09:46:05 by vtenneke       #+#    #+#                */
/*   Updated: 2019/12/04 12:46:34 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	k;

	k = 0;
	if (s1 == 0)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	dest = (char*)malloc(i + 1);
	if (!(dest))
		return (NULL);
	while (*s1)
	{
		dest[k] = *s1;
		s1++;
		k++;
	}
	while (*s2)
	{
		dest[k] = *s2;
		s2++;
		k++;
	}
	dest[k] = '\0';
	return (dest);
}
