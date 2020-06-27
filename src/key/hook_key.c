/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_key.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 17:29:35 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/20 17:29:35 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Redirect key input to the associated functions.
**
**	@param	:	{int} keycode
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#include <minirt.h>
#include <mlx.h>
#include "hook_key.h"
#include <stdlib.h>

int		hook_key(int keycode, t_data *data)
{
	char	*keystring;

	(void)data;
	keystring = ft_itoa(keycode);
	mlx_string_put(data->mlx_info.mlx, data->mlx_info.mlx_win,
		(data->window.x / 2) - 10, 20, 0xFFFFFF, keystring);
	free(keystring);
	key(keycode, data);
	return (0);
}

void	key(int keycode, t_data *data)
{
	uint8_t i;

	i = 0;
	while (g_hook_key[i].func)
	{
		if (g_hook_key[i].key == keycode)
		{
			g_hook_key[i].func(keycode, data);
			return ;
		}
		i++;
	}
}
