/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_to_matrix.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 13:44:55 by vtenneke       #+#    #+#                */
/*   Updated: 2020/03/04 13:44:55 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	quat_to_matrix(t_quat q)
{
	t_matrix res;

	res.right.x = 1 - 2 * pow(q.y, 2) - 2 * pow(q.z, 2);
	res.right.y = 2 * q.x * q.y - 2 * q.w * q.z;
	res.right.z = 2 * q.x * q.z + 2 * q.w * q.y;
	res.up.x = 2 * q.x * q.y + 2 * q.w * q.z;
	res.up.y = 1 - 2 * pow(q.x, 2) - 2 * pow(q.z, 2);
	res.up.z = 2 * q.y * q.z + 2 * q.w * q.x;
	res.forward.x = 2 * q.x * q.z - 2 * q.w * q.y;
	res.forward.y = 2 * q.y * q.z - 2 * q.w * q.x;
	res.forward.z = 1 - 2 * pow(q.x, 2) - 2 * pow(q.y, 2);

	return (res);
}
