/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:12:05 by vtenneke       #+#    #+#                */
/*   Updated: 2019/12/04 12:56:19 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;
	size_t tmp;

	dstlen = 0;
	tmp = 0;
	while (dst[dstlen] && dstsize > dstlen)
		dstlen++;
	while (tmp < dstsize - dstlen - 1 && src[tmp] && dstsize > dstlen)
	{
		dst[dstlen + tmp] = src[tmp];
		tmp++;
	}
	if (dstsize > dstlen)
		dst[dstlen + tmp] = '\0';
	while (src[tmp])
		tmp++;
	if (dstsize < dstlen)
		return (tmp + dstsize);
	return (dstlen + tmp);
}
