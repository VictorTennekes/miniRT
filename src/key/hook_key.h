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

void	cam_move(int keycode, t_data *data);
void	cam_rotate(int keycode, t_data *data);
void	cam_move_v2(int keycode, t_data *data);

t_hook_key		g_hook_key[] = {
	{KEY_ESC, &exit_mlx},
	{KEY_Q, &exit_mlx},
	// {KEY_O, &switch_cam},
	// {KEY_P, &switch_cam},
	{KEY_A, &cam_move},
	{KEY_D, &cam_move},
	{KEY_W, &cam_move},
	{KEY_S, &cam_move},
	{KEY_LSHIFT, &cam_move},
	{KEY_SPACE, &cam_move},
	{KEY_LEFT, &cam_rotate},
	{KEY_RIGHT, &cam_rotate},
	{KEY_UP, &cam_rotate},
	{KEY_DOWN, &cam_rotate},
	{0, NULL}
};

#endif