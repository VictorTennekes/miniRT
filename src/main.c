/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:59 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/10 09:23:45 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	The main function of the program, checks the arguments and links to
**	needed functions.
**
**	@param	:	{int} ac
**	@param	:	{char **} av
**
**	@return	:	{int}
*/

#include <minirt.h>
#include <mlx.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 && ac != 3)
		print_error("Invalid amount of arguments", &data);
	ft_bzero(&data, sizeof(t_data));
	if (ac == 3)
	{
		if (!(ft_strcmp(av[2], "--save")))
			data.mapinfo.save = true;
		else
			print_error("Invalid argument", &data);
	}
	parse_file(av[1], &data);
	if (!data.cameras->content)
		print_error("No camera", &data);
	data.current_cam = data.cameras->content;
	if (init_mlx(&data))
		print_error("Can't open window", &data);
	mlx_loop(data.mlx_info.mlx);
	return (0);
}
