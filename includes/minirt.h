/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:59:52 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/28 12:58:04 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdint.h>
# include <stdbool.h>
# include <stddef.h>

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

typedef struct		s_window
{
	uint16_t			x;
	uint16_t			y;
	bool				res_set;
}					t_window;

typedef struct		s_map_info
{
	bool			save;
}					t_map_info;

typedef struct		s_data
{
	t_object		object;
	t_window		window;
	t_map_info		mapinfo;
}					t_data;

// error
void print_error(char *error);

// parsing
void	parse_file(char *file, t_data *data);
void	parse_line(char *line, t_data *data);

int		verify_filename(char *filename);

void	parse_resolution(char **info, t_data *data);

size_t	char_arrlen(char **array);

int		isdigit_str(char *str);


# endif