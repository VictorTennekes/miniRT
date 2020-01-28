/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:56:02 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/24 17:01:34 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void print_error(char *error)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(error, 1);
	exit(1);
}