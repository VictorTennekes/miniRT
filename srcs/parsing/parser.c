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
	if (filename[i-2] == '.' && filename[i-1] == 'r' && filename[i] == 't')
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
	if (!(ft_strncmp(info[0], "R", 1)))
		printf("parse resolution");
	if (!(ft_strncmp(info[0], "A", 1)))
		printf("parse ambient lighting");
	if (!(ft_strncmp(info[0], "c", 1)))
		printf("parse camera");
	if (!(ft_strncmp(info[0], "l", 1)))
		printf("parse light");
	if (!(ft_strncmp(info[0], "pl", 2)))
		printf("parse plane");
	if (!(ft_strncmp(info[0], "sp", 2)))
		printf("parse sphere");
	if (!(ft_strncmp(info[0], "sq", 2)))
		printf("parse square");
	if (!(ft_strncmp(info[0], "cy", 2)))
		printf("parse cylinder");
	if (!(ft_strncmp(info[0], "tr", 2)))
		printf("parse triangle");
}

void	parse_file(char *file, t_data *data)
{
	int		fd;
	char 	*line;

	if (!(verify_filename(file)))
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
