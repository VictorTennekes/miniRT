/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:59 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/03 16:51:21 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 && ac != 3)
		print_error("Invalid amount of arguments");
	ft_bzero(&data, sizeof(t_data));
	if (ac == 3)
	{
		if (!(ft_strncmp(av[2], "--save", 6)))
			data.mapinfo.save = true;
		else
			print_error("Invalid argument");
	}
	parse_file(av[1], &data);
	// while (1);
	return (0);
}