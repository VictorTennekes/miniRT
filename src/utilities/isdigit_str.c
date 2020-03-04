/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: victor <victor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 12:24:50 by victor         #+#    #+#                */
/*   Updated: 2020/02/03 17:47:04 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Calculating if a string contains only digits.
**
**	@param	:	{char *} str
**
**	@return	:	{int}
*/

#include <minirt.h>

int		isdigit_str(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}