/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_line.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 16:12:12 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/03 16:19:17 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <libft.h>

bool	check_line(char *str)
{
	while (*str != '\n')
	{
		if (ft_isascii(*str))
			return (false);
		str++;
	}
	return (true);
}