/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:59:52 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/06 13:27:26 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdint.h>
# include <stdbool.h>
# include <stddef.h>
# include <liblist.h>

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

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_object
{
	t_object_type	type;
	t_coord			pos;
	t_coord			pos2;
	t_coord			pos3;
	t_coord			vector;
	t_color			color;
	double			size;
	double			height;
}					t_object;

typedef struct		s_camera
{
	t_coord			pos;
	t_coord			vector;
	uint8_t			fov;
	double			distance;
}					t_camera;

typedef struct		s_light
{
	t_coord			pos;
	double			ratio;
	t_color			color;
}					t_light;

typedef struct		s_window
{
	uint16_t		x;
	uint16_t		y;
	bool			res_set;
}					t_window;

typedef struct		s_map_info
{
	bool			save;
	double			amb_ratio;
	t_color			amb_color;
	bool			amb_set;

}					t_map_info;

typedef struct		s_data
{
	t_list			*objects;
	t_list			*cameras;
	t_list			*lights;
	t_window		window;
	t_map_info		mapinfo;
}					t_data;

// error
void 	print_error(char *error);

// parsing
void	parse_file(char *file, t_data *data);
void	parse_line(char *line, t_data *data);
int		verify_filename(char *filename);

// utils
size_t	char_arrlen(char **array);
int		isdigit_str(char *str);
double	parse_double(char *str);
t_color	parse_color(char *str);
t_coord	parse_coord(char *str);
void	*free_machine(char **array);
bool	check_line(char *str);

//  parsing
void	parse_resolution(char **info, t_data *data);
void	parse_ambient(char **info, t_data *data);
void	parse_camera(char **info, t_data *data);
void	parse_light(char **info, t_data *data);
void	parse_sphere(char **info, t_data *data);
void	parse_plane(char **info, t_data *data);
void	parse_square(char **info, t_data *data);
void	parse_cylinder(char **info, t_data *data);
void	parse_triangle(char **info, t_data * data);

// calculations
double	calc_square(t_object *object, t_data *data);

void	calc_fov(t_data *data);

double	calc_distance_points(t_coord *pos1, t_coord *pos2);

# endif