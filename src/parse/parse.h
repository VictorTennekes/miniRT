/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 11:53:49 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/20 11:53:49 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <minirt.h>

void	parse_resolution(char **info, t_data *data);
void	parse_ambient(char **info, t_data *data);


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
	{"tr", &parse_triangle}
};

#endif