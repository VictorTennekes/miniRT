/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_machine.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 11:19:21 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/03 16:51:02 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Function to free an array.
**
**	@param	:	{char **} array
**
**	@return	:	{void}
*/

#include <stdlib.h>
#include <stdio.h>

void	*free_machine(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
