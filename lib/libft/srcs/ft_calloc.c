/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 15:10:37 by vtenneke      #+#    #+#                 */
/*   Updated: 2019/11/08 14:42:12 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*block;
	size_t	total_size;

	total_size = count * size;
	block = (void *)malloc(total_size);
	if (!(block))
		return (NULL);
	ft_bzero(block, total_size);
	return (block);
}
