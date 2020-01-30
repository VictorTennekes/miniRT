/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:59 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/30 09:44:42 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <stdio.h>
#include <fcntl.h>
#include <get_next_line_bonus.h>
#include <minirt.h>

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 && ac != 3)
		print_error("Invalid amount of arguments.");
	ft_bzero(&data, sizeof(t_data));
	if (ac == 3)
	{
		if (!(ft_strncmp(av[2], "--save", 6)))
			data.mapinfo.save = true;
		else
			print_error("Invalid argument.");
	}
	parse_file(av[1], &data);

	// test print
	printf("screen res x:%i\nscreen res y:%i\n", data.window.x, data.window.y);
	printf("ambient ratio:%f\n", data.mapinfo.amb_ratio);
	printf("	r:%u\n	g:%u\n	b:%u\n", data.mapinfo.amb_color.r, \
		data.mapinfo.amb_color.g, data.mapinfo.amb_color.b);
	return (0);
}