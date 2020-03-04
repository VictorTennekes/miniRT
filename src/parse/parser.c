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
#include <get_next_line_bonus.h>
#include "parse.h"

/*
**	Verifying if the passed file has a .rt extention.
**
**	@param	:	{char *} filename
**
**	@return	:	{void}
*/

static bool	verify_filename(char *filename)
{
	int i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i-2] == '.' && filename[i-1] == 'r' && filename[i] == 't')
		return (false);
	return (true);
}

/*
**	Parsing first word of line to know what specifier it's dealing with.
**
**	@param	:	{char *} line
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

static void	parse_line(char *line, t_data *data)
{
	char	**info;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	info = ft_split(line, ' ');
	if (info == NULL)
		print_error("Memory allocation failed.", data);
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

/*
**	Retrieving individual lines to utilize in parsing
**
**	@param	:	{char *} file
**	@param	:	{t_data *} data
**
**	@return	:	{void}
*/

void		parse_file(char *file, t_data *data)
{
	int		fd;
	char 	*line;
	int		ret;

	if (verify_filename(file) == false)
		print_error("Invalid file extention", data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Can't open file", data);
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (*line != '#')
			parse_line(line, data);
		free (line);
	}
	if (!data->mapinfo.amb_set || !data->window.res_set)
		print_error("Invalid file: resolution and ambient have to be set", data);
	if (!data->cameras || !data->lights)
		print_error("Invalid file: at least one light and camera have to be set", data);
	data->current_cam = data->cameras->content;
	close (fd);
}
