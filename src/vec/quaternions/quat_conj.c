/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_conj.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:41:50 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/04 13:41:50 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_quat quat_conj(t_quat q)
{
	t_quat new;

	new.w = q.w;
	new.x = -q.x;
	new.y = -q.y;
	new.z = -q.z;
	return (new);
}