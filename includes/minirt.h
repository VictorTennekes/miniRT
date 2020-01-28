/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:59:52 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/27 13:33:04 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdint.h>
# include <stdbool.h>

typedef enum		e_object_type
{
	PL,
	SP,
	SQ,
	CY,
	TR
}					t_object_type;

typedef struct		s_color
{
	uint8_t			r;
	uint8_t			g;
	uint8_t 		b;
}					t_color;

typedef struct		s_object
{
	t_object_type	type;
	t_color			color;
	float			size;
	float			height;
}					t_object;

typedef struct		s_map_info
{
	bool			save;
}					t_map_info;

typedef struct		s_data
{
	t_object		object;
	t_map_info		mapinfo;
}					t_data;

// error
void print_error(char *error);

// parsing
void	parse_file(char *file, t_data *data);
void	parse_line(char *line, t_data *data);
int		verify_filename(char *filename);


# endif