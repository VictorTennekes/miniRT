/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:59:52 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/11 14:19:47 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdint.h>
# include <stdbool.h>
# include <stddef.h>
# include <liblist.h>
# include <math.h>
# include <stdio.h>

// Globally needed structs

typedef struct		s_color
{
	double			r;
	double			g;
	double 		b;
}					t_color;

// Vectors and rays
typedef struct		s_vec3d
{
	double			x;
	double			y;
	double			z;
}					t_vec3d;

typedef struct		s_vec2ui
{
	uint16_t		x;
	uint16_t		y;
}					t_vec2ui;

typedef struct		s_ray
{
	t_vec3d			origin;
	t_vec3d			direction;
}					t_ray;

typedef enum		e_object_type
{
	PL,
	SP,
	SQ,
	CY,
	TR
}					t_object_type;

typedef struct		s_object
{
	t_object_type	type;
	t_vec3d			pos;
	t_vec3d			pos2;
	t_vec3d			pos3;
	t_vec3d			vector;
	t_color			color;
	double			size;
	double			height;
}					t_object;

typedef struct		s_ray_res
{
	double			distance;
	t_vec3d			position;
	t_color			color;
	t_object		*object;
}					t_ray_res;

// General stuff

typedef struct		s_mlx_data
{
	void			*img;
    char			*addr;
    int				bits_per_pixel;
    int				line_length;
    int				endian;
}					t_mlx_data;


typedef struct		s_mlxinfo
{
	void			*mlx;
	void			*mlx_win;
	t_mlx_data		mlx_data;
}					t_mlxinfo;


typedef struct		s_camera
{
	t_vec3d			pos;
	t_vec3d			vector;
	uint8_t			fov;
	double			distance;
}					t_camera;

typedef struct		s_light
{
	t_vec3d			pos;
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
	t_camera		*current_cam;
	t_list			*lights;
	t_window		window;
	t_map_info		mapinfo;
	t_mlxinfo		mlx_info;
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
t_vec3d	parse_coord(char *str);
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

double	calc_distance_points(t_vec3d *pos1, t_vec3d *pos2);


// Vector functions
t_vec3d	normalize_coords(t_vec3d coord, t_data *data);
t_color	get_pixel(t_vec2ui pixel, t_data *data);

// Vector utilities
t_vec3d	vec_new(double x, double y, double z);
t_vec3d	vec_add(t_vec3d vec1, t_vec3d vec2);
t_vec3d	vec_sub(t_vec3d vec1, t_vec3d vec2);
t_vec3d	vec_a_to_b(t_vec3d a, t_vec3d b);
t_vec3d vec_normalize(t_vec3d coord);
double	vec_len(t_vec3d vec);
double	vec_dot_prod(t_vec3d vec1, t_vec3d vec2);
t_vec3d	vec_multi(t_vec3d vec, double factor);

// Rays
t_color cast_ray(t_ray ray, t_data *data);
t_ray_res	cast_ray_object(t_ray ray, t_data *data);

// Ray Res
t_ray_res 	ray_res_new(t_object *object, t_vec3d vector, t_color color);
t_ray_res	ray_res_dist_new(t_object *object, t_vec3d vector, t_color color, \
	double distance);
t_ray_res 	ray_res_inf(void);

// Dist
t_ray_res	obj_dist(t_object *obj, t_ray ray, t_data *data);

// MLX
bool	init_mlx(t_data *data);
bool	init_mlx_img(t_data *data);

int	color_to_int(t_color color);
void	pixel_put(t_mlx_data data, int x, int y, t_color color);
int		hook_frame(t_data *data);

# endif