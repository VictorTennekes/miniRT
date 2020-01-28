/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:59 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/24 17:04:33 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <stdio.h>
#include <fcntl.h>
#include <get_next_line_bonus.h>
#include <minirt.h>

// int main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;
// 	int		ret;

// 	if (ac == 2)
// 	{
// 		fd = open(av[1], O_RDONLY);
// 		if (fd == -1)
// 			return (-1);
// 		ret = 1;
// 		while (ret > 0)
// 		{
// 			ret = get_next_line(fd, &line);
// 			if (ret < 0)
// 				return (-1);
// 			printf("line: %s\n", line);
// 		}
// 	}
// 	return (0);
// }

int main(int ac, char **av)
{
	t_data data;

	if (ac != 2 && ac != 3)
		print_error("Invalid amount of arguments.\n");
	ft_bzero(&data, sizeof(t_data));
	if (ac == 3)
	{
		if (!(ft_strncmp(av[2], "--save",)))
			data.mapinfo.save = true;
		else
			print_error("Invalid argument.\n");
	}
	parse_file(av[1], &data);
	return (0);
}