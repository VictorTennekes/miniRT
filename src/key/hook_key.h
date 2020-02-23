/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_key.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 11:24:40 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/21 11:24:40 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_KEY_H
# define HOOK_KEY_H

# include <minirt.h>
# include <key_codes.h>

typedef struct	s_hook_key
{
	int			key;
	void		(*func)(int, t_data *);
}				t_hook_key;



t_hook_key		g_hook_key[] = {
	{KEY_ESC, &exit_mlx},
	{KEY_A, &cam_move},
	{KEY_D, &cam_move},
	{KEY_W, &cam_move},
	{KEY_S, &cam_move},
	{KEY_LSHIFT, &cam_move},
	{KEY_SPACE, &cam_move},
	{0, NULL}
};

#endif