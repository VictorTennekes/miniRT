/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:01 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/10 20:45:27 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <fcntl.h>
#include <libft.h>
#include <get_next_line_bonus.h>
#include "parse.h"

#include <stdio.h>

// Verifying if the file has the .rt extension
int		verify_filename(char *filename)
{
	int i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i-2] == '.' && filename[i-1] == 'r' && filename[i] == 't')
		return (1);
	return (0);
}

// Parsing the first word to see what type of specifier i'm dealing with
void	parse_line(char *line, t_data *data)
{
	char	**info;
	int		i;

	info = ft_split(line, ' ');
	if (info == NULL)
		print_error("Memory allocation failed.");
	if (!info[0])
	{
		free_machine(info);
		return ;
	}
	i = 0;
	while (g_parse[i].id)
	{
		if (!ft_strcmp(info[0], g_parse[i].id))
		{
			g_parse[i].func(info, data);
			free_machine(info);
			return ;
		}
		i++;
	}
}

// Parsing the file so i can analyze the individual lines
void	parse_file(char *file, t_data *data)
{
	int		fd;
	char 	*line;
	int		ret;

	if (verify_filename(file))
		print_error("Invalid file extention");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Can't open file");
	ret = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line != '#')
			parse_line(line, data);
		free (line);
	}
	if (!data->mapinfo.amb_set || !data->window.res_set)
		print_error("Invalid file: resolution and ambient have to be set");
	if (!data->cameras || !data->lights)
		print_error("At least one light and camera have to be set");
	close (fd);
}
