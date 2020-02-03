/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:59 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/03 10:35:33 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <stdio.h>
#include <fcntl.h>
#include <get_next_line_bonus.h>
#include <minirt.h>

// TODO: parse plane
// TODO: parse square
// TODO: parse cylinder
// TODO: parse triangle

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
	int i = 1;
	while (i == 1)
	{
		
	}
	return (0);
}