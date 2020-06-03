/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_arrlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:16:42 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:16:42 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculating the size of a char array.
**
**	@param	:	{char **} array
**
**	@return	:	{size_t}
*/

#include <stddef.h>

size_t	char_arrlen(char **array)
{
	size_t	res;

	res = 0;
	while (array[res])
		res++;
	return (res);
}
