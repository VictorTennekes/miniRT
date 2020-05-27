/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 11:53:49 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/02/20 11:53:49 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Redirecting the parse function for appropriate identifier.
**
**	@param	:	{char **} info
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

#ifndef PARSE_H
# define PARSE_H

# include <minirt.h>

void			parse_resolution(char **info, t_data *data);
void			parse_ambient(char **info, t_data *data);
void			parse_camera(char **info, t_data *data);
void			parse_light(char **info, t_data *data);
void			parse_plane(char **info, t_data *data);
void			parse_sphere(char **info, t_data *data);
void			parse_square(char **info, t_data *data);
void			parse_cylinder(char **info, t_data *data);
void			parse_triangle(char **info, t_data *data);
void			parse_disk(char **info, t_data *data);
void			parse_pyramid(char **info, t_data *data);

typedef struct	s_parse
{
	char		*id;
	void		(*func)(char **, t_data *);
}				t_parse;

t_parse			g_parse[] = {
	{"R", &parse_resolution},
	{"A", &parse_ambient},
	{"c", &parse_camera},
	{"l", &parse_light},
	{"pl", &parse_plane},
	{"sp", &parse_sphere},
	{"sq", &parse_square},
	{"cy", &parse_cylinder},
	{"tr", &parse_triangle},
	{"ds", &parse_disk},
	{"py", &parse_pyramid}
};

#endif
