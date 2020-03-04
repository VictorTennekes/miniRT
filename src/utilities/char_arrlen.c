/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_arrlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 12:18:26 by victor         #+#    #+#                */
/*   Updated: 2020/01/28 12:20:27 by victor        ########   odam.nl         */
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