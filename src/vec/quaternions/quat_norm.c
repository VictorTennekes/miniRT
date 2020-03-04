/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_norm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:42:16 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/04 13:42:16 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_quat	quat_norm(t_quat q)
{
	t_quat new;
	double	mag;

	mag = sqrt(pow(q.w, 2) + pow(q.x, 2) + pow(q.y, 2) + pow(q.z, 2));
	new.w = q.w / mag;
	new.x = q.x / mag;
	new.y = q.y / mag;
	new.z = q.z / mag;
	return (new);
}