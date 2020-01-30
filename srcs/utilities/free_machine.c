/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_machine.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 11:19:21 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/30 11:29:25 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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