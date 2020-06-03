/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:17:48 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:17:48 by vtenneke      ########   odam.nl         */
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
