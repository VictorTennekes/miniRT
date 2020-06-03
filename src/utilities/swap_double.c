/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_double.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 18:53:34 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/03/10 18:53:34 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

inline void	swap_double(double *d1, double *d2)
{
	double tmp;

	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}
