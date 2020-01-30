/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:01 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/30 11:29:47 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <fcntl.h>
#include <libft.h>
#include <get_next_line_bonus.h>

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
	char **info;

	info = ft_split(line, ' ');
	if (info == NULL)
		print_error("Memory allocation failed.");
	if (!info[0])
		return ;
	if (!(ft_strncmp(info[0], "R", 1)))
		parse_resolution(info, data);
	else if (!(ft_strncmp(info[0], "A", 1)))
		parse_ambient(info, data);
	else if (!(ft_strncmp(info[0], "c", 2)))
		parse_camera(info, data);
	else if (!(ft_strncmp(info[0], "l", 2)))
		printf("parse light\n");
	else if (!(ft_strncmp(info[0], "pl", 2)))
		printf("parse plane\n");
	else if (!(ft_strncmp(info[0], "sp", 2)))
		printf("parse sphere\n");
	else if (!(ft_strncmp(info[0], "sq", 2)))
		printf("parse square\n");
	else if (!(ft_strncmp(info[0], "cy", 2)))
		printf("parse cylinder\n");
	else if (!(ft_strncmp(info[0], "tr", 2)))
		printf("parse triangle\n");
}

// Parsing the file so i can analyze the individual lines
void	parse_file(char *file, t_data *data)
{
	int		fd;
	char 	*line;
	int		ret;

	if (verify_filename(file))
		print_error("Invalid file extention.");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Can't open file.");
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			print_error("Error while getting line.");
		if (*line != '#')
			parse_line(line, data);
		free(line);
	}
	close (fd);
}
