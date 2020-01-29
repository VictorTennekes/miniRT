/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:59:52 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/27 17:12:56 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdint.h>
# include <libft.h>
# include <liblist.h>

typedef struct s_color
{
	uint8_t		red;
	uint8_t 	green;
	uint8_t 	blue;
}				t_color;


typedef enum	e_object_type {
	PL,
	SP,
	SQ,
	CY,
	TR
}				t_object_type;

typedef struct	s_object {
	t_object_type	type;
	t_color			color;
	float			size;
	float			height;
}				t_object;


void print_error(char *error);

# endif
