/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:01 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/24 16:51:44 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <fcntl.h>
#include <libft.h>
#include <get_next_line_bonus.h>

#include <stdio.h>

int		verify_filename(char *filename)
{
	int i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i-2] == "." && filename[i-1] == "r" && filename[i] == "t")
		return (1);
	return (0);
}

void	parse_line(char *line, t_data *data)
{
	char **info;

	info = ft_split(line, ' ');
	if (info == NULL)
		print_error("Memory allocation failed\n");
	if (!info[0])
		return ;
	if (info[0] == "R")
		printf("parse resolution");
	if (info[0] == "A")
		printf("parse ambient lighting");
	if (info[0] == "c")
		printf("parse camera");
	if (info[0] == "l")
		printf("parse light");
	if (info[0] == "pl")
		printf("parse plane");
	if (info[0] == "sp")
		printf("parse sphere");
	if (info[0] == "sq")
		printf("parse square");
	if (info[0] == "cy")
		printf("parse cylinder");
	if (info[0] == "tr")
		printf("parse triangle");
}

void	parse_file(char *file, t_data *data)
{
	int		fd;
	char 	*line;

	if (!(verify_filename))
		print_error("Invalid file extention\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Can't open file");
	while (get_next_line(fd, &line))
	{
		if (*line != '#')
			parse_line(line, data);
		free(line);
	}
	close (fd);
}
