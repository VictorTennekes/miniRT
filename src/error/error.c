/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:56:02 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/05 18:46:37 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Collection of functions for printing errors
**
**	@param	:	{char *} error
**	@param	:	{t_data} *data
**	@param	:	{void *} func
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <stdlib.h>

void	print_error(char *error, t_data *data)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(error, 1);
	ft_putstr_fd("\n", 1);
	if (data)
		free_data(data);
	exit(1);
}

void	print_error_free(char *error, void *free,
				void (*func)(void *), t_data *data)
{
	func(free);
	print_error(error, data);
}

void	exit_free(t_data *data)
{
	free_data(data);
	exit(1);
}
