/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:59:52 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/11 14:19:47 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define MOVE_SPEED 0.6

# include <libft.h>
# include <liblist.h>
# include <stdint.h>
# include <stdbool.h>
# include <stddef.h>
# include <math.h>
# include <stdio.h>

/*
**	Color
*/

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

/*
**	Rays and vectors
*/

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

/*
**	Matrices
*/

typedef struct		s_matrix
{
	t_vec3d			forward;
	t_vec3d			right;
	t_vec3d			up;
	t_vec3d			translation;
}					t_matrix;

typedef struct		s_quat
{
	double			w;
	double			x;
	double			y;
	double			z;
}					t_quat;

/*
**	Objects
*/

typedef enum		e_object_type
{
	PL,
	SP,
	SQ,
	CY,
	TR,
	DS
}					t_object_type;

typedef struct		s_object
{
	t_object_type	type;
	t_vec3d			pos[3];
	t_vec3d			vector;
	t_color			color;
	double			size;
	double			height;
}					t_object;

/*
**	Ray results
*/

typedef struct		s_ray_res
{
	t_object		*object;
	t_vec3d			position;
	t_color			color;
	double			distance;
}					t_ray_res;

/*
**	General structs
*/

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
	t_matrix		matrix;
	uint8_t			fov;
	double			distance;
	t_quat			quat;
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
	bool			rendered;
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

/*
**	Error functions
*/

void				print_error(char *error, t_data *data);
void				print_error_free(char *error, void *free,
						void (*func)(void *), t_data *data);
void				exit_free(t_data *data);

/*
**	Free functions
*/

void				free_data(t_data *data);
void				free_list(t_list *list, void (*func)(void *));

/*
**	Parse function
*/

void				parse_file(char *file, t_data *data);

/*
**	Utility functions
*/

size_t				char_arrlen(char **array);
int					isdigit_str(char *str);
double				parse_double(char *str);
t_color				parse_color(char *str, t_data *data);
t_vec3d				parse_coord(char *str);
void				*free_machine(char **array);
bool				check_line(char *str);
int					color_to_int(t_color color);
bool				double_compare(double a, double b);
double				check_edge_tr(t_object *triangle, t_vec3d normal, t_vec3d p);
void				swap_double(double *d1, double *d2);
void				init_sq_children(t_object *square, t_data *data);

/*
**	Vector functions and utilities
*/

t_color				get_pixel(t_vec2ui pixel, t_data *data);
t_vec3d				multi_vec_matrix(t_vec3d vec, t_matrix matrix);
t_vec3d				vec_a_to_b(t_vec3d a, t_vec3d b);
t_vec3d				vec_add(t_vec3d vec1, t_vec3d vec2);
t_vec3d				normalize_coords(t_vec3d coord, t_data *data);
t_vec3d				vec_new(double x, double y, double z);
double				vec_dist(t_vec3d vec1, t_vec3d vec2);
t_vec3d				vec_sub(t_vec3d vec1, t_vec3d vec2);
t_vec3d				vec_normalize(t_vec3d coord);
double				vec_len(t_vec3d vec);
double				vec_dot_prod(t_vec3d vec1, t_vec3d vec2);
t_vec3d				vec_multi(t_vec3d vec, double factor);
t_vec3d				vec_cross_prod(t_vec3d vec1, t_vec3d vec2);
t_vec3d				vec_prod(t_vec3d vec1, t_vec3d vec2);

/*
**	Ray and ray_res functions
*/

t_ray_res			ray_res_new(t_object *object, t_vec3d vector,
						t_color color);
t_ray_res			ray_res_dist_new(t_object *object, t_vec3d vector,
						t_color color,
						double distance);
t_ray_res			ray_res_inf(void);
t_color				cast_ray(t_ray ray, t_data *data);
t_ray_res			cast_ray_object(t_ray ray, t_data *data);
t_ray				ray_new(t_vec3d origin, t_vec3d direction);
t_ray_res			obj_dist(t_object *obj, t_ray ray, t_data *data);

/*
**	MLX functions
*/

void				exit_mlx(int keycode, t_data *data);
int					hook_frame(t_data *data);
bool				init_mlx_img(t_data *data);
bool				init_mlx(t_data *data);
void				pixel_put(t_mlx_data data, int x, int y, t_color color);

/*
**	Normalizing main function
*/

t_vec3d				normal(t_ray_res ray_res, t_ray ray, t_data *data);
t_vec3d				adjust_normal(t_vec3d ray_dir, t_vec3d norm);

/*
**	Light functions
*/

t_color				cast_all_light(t_ray_res ray_res, t_ray ray, t_data *data);

/*
**	Color functions
*/

t_color				color_multi(t_color color, double fact);
t_color				color_mix(t_color c1, t_color c2);
t_color				color_mix_light(t_color color, t_color light);
t_color				color_new(uint8_t r, uint8_t g, uint8_t b);
t_color				color_add_light(t_color col1, t_color col2);

/*
**	Intersections main function
*/

double				intersect(t_object *obj, t_ray ray, t_data *data);

/*
**	Key main functions
*/

int					hook_key(int keycode, t_data *data);
void				key(int keycode, t_data *data);

/*
**	Matrix and quaternion functions
*/

t_matrix			quat_to_matrix(t_quat q);
t_matrix			matrix_new(t_vec3d f);
t_matrix			matrix_multi(t_matrix m, double d);
t_matrix			normal_matrix(t_matrix matrix);
t_quat				quat_conj(t_quat q);
t_quat				quat_norm(t_quat q);
t_quat				quat_new(double w, double x, double y, double z);
t_quat				quat_local_rot(t_vec3d axis, double angle);
t_quat				quat_multi(t_quat q1, t_quat q2);

/*
**	Main camera function
*/

t_quat				rotate_cam(t_vec3d vector, t_vec3d axis, double angle);

/*
** Bmp function
*/

void				save_bmp(t_data *data);

#endif
