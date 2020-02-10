/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:01 by vtenneke       #+#    #+#                */
/*   Updated: 2020/02/10 11:25:08 by vtenneke      ########   odam.nl         */
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
	{
		free_machine(info);
		return ;
	}
	if (!(ft_strncmp(info[0], "R", 1)))
		parse_resolution(info, data);
	else if (!(ft_strncmp(info[0], "A", 1)))
		parse_ambient(info, data);
	else if (!(ft_strncmp(info[0], "c", 2)))
		parse_camera(info, data);
	else if (!(ft_strncmp(info[0], "l", 2)))
		parse_light(info, data);
	else if (!(ft_strncmp(info[0], "pl", 2)))
		parse_plane(info, data);
	else if (!(ft_strncmp(info[0], "sp", 2)))
		parse_sphere(info, data);
	else if (!(ft_strncmp(info[0], "sq", 2)))
		parse_square(info, data);
	else if (!(ft_strncmp(info[0], "cy", 2)))
		parse_cylinder(info, data);
	else if (!(ft_strncmp(info[0], "tr", 2)))
		parse_triangle(info, data);
	free_machine(info);
}

void	loop_list_data(t_data *data)
{
	t_camera	*camera;
	t_light		*light;
	t_object	*sphere;
	t_object	*plane;
	t_object	*square;
	t_object	*cylinder;
	t_object	*triangle;

	camera = data->cameras->content;
	light = data->lights->content;
	sphere = data->objects->content;
	
	// * Plane
	data->objects = data->objects->next;
	plane = data->objects->content;
	
	// * Square
	data->objects = data->objects->next;
	square = data->objects->content;

	// * Cylinder
	data->objects = data->objects->next;
	cylinder = data->objects->content;

	// * Triangle
	data->objects = data->objects->next;
	triangle = data->objects->content;

	printf("screen res_x:		%u\n", data->window.x);
	printf("screen res_y:		%u\n", data->window.y);
	printf("res_set:		%s\n", data->window.res_set?"true":"false");
	printf("\n");

	printf("map save:		%s\n", data->mapinfo.save?"true":"false");
	printf("map amb_ratio:		%f\n", data->mapinfo.amb_ratio);
	printf("map amb_color_r:	%f\n", data->mapinfo.amb_color.r);
	printf("map amb_color_g:	%f\n", data->mapinfo.amb_color.g);
	printf("map amb_color_b:	%f\n", data->mapinfo.amb_color.b);
	printf("map amb_set:		%s\n", data->mapinfo.amb_set?"true":"false");
	printf("\n");
	
	printf("camera fov: 		%i\n", camera->fov);
	printf("camera pos_x:		%f\n", camera->pos.x);
	printf("camera pos_y:		%f\n", camera->pos.y);
	printf("camera pos_z:		%f\n", camera->pos.z);
	calc_fov(data);
	printf("\n");

	// settings list to next camera
	data->cameras = data->cameras->next;
	camera = data->cameras->content;

	printf("camera_2 fov: 		%i\n", camera->fov);
	printf("camera_2 pos_x:		%f\n", camera->pos.x);
	printf("camera_2 pos_y:		%f\n", camera->pos.y);
	printf("camera_2 pos_z:		%f\n", camera->pos.z);
	calc_fov(data);
	printf("\n");

	printf("light ratio:		%f\n", light->ratio);
	printf("light pos_x:		%f\n", light->pos.x);
	printf("light pos_y:		%f\n", light->pos.y);
	printf("light pos_z:		%f\n", light->pos.z);
	printf("light color_r:		%f\n", light->color.r);
	printf("light color_g:		%f\n", light->color.g);
	printf("light color_b:		%f\n", light->color.b);
	printf("\n");

	printf("sphere size:		%f\n", sphere->size);
	printf("sphere pos_x:		%f\n", sphere->pos.x);
	printf("sphere pos_y:		%f\n", sphere->pos.y);
	printf("sphere pos_z:		%f\n", sphere->pos.z);
	printf("sphere color_r:		%f\n", sphere->color.r);
	printf("sphere color_g:		%f\n", sphere->color.g);
	printf("sphere color_b:		%f\n", sphere->color.b);
	printf("\n");

	printf("plane pos_x:		%f\n", plane->pos.x);
	printf("plane pos_y:		%f\n", plane->pos.y);
	printf("plane pos_z:		%f\n", plane->pos.z);
	printf("plane vector_x:		%f\n", plane->vector.x);
	printf("plane vector_y:		%f\n", plane->vector.y);
	printf("plane vector_z:		%f\n", plane->vector.z);
	printf("plane color_r:		%f\n", plane->color.r);
	printf("plane color_g:		%f\n", plane->color.g);
	printf("plane color_b:		%f\n", plane->color.b);
	printf("\n");

	printf("square pos_x:		%f\n", square->pos.x);
	printf("square pos_y:		%f\n", square->pos.y);
	printf("square pos_z:		%f\n", square->pos.z);
	printf("square vector_x:	%f\n", square->vector.x);
	printf("square vector_y:	%f\n", square->vector.y);
	printf("square vector_z:	%f\n", square->vector.z);
	printf("square size:		%f\n", square->size);
	printf("square color_r:		%f\n", square->color.r);
	printf("square color_g:		%f\n", square->color.g);
	printf("square color_b:		%f\n", square->color.b);
	printf("square dis t p:		%f\n", calc_square(square, data));
	printf("\n");

	printf("cylinder pos_x:		%f\n", cylinder->pos.x);
	printf("cylinder pos_y:		%f\n", cylinder->pos.y);
	printf("cylinder pos_z:		%f\n", cylinder->pos.z);
	printf("cylinder vector_x:	%f\n", cylinder->vector.x);
	printf("cylinder vector_y:	%f\n", cylinder->vector.y);
	printf("cylinder vector_z:	%f\n", cylinder->vector.z);
	printf("cylinder size:		%f\n", cylinder->size);
	printf("cylinder height:	%f\n", cylinder->height);
	printf("cylinder color_r:	%f\n", cylinder->color.r);
	printf("cylinder color_g:	%f\n", cylinder->color.g);
	printf("cylinder color_b:	%f\n", cylinder->color.b);
	printf("\n");

	printf("triangle pos_x:		%f\n", triangle->pos.x);
	printf("triangle pos_y:		%f\n", triangle->pos.y);
	printf("triangle pos_z:		%f\n", triangle->pos.z);
	printf("triangle pos2:		%f\n", triangle->pos2.x);
	printf("triangle pos2:		%f\n", triangle->pos2.y);
	printf("triangle pos2:		%f\n", triangle->pos2.z);
	printf("triangle pos3:		%f\n", triangle->pos3.x);
	printf("triangle pos3:		%f\n", triangle->pos3.y);
	printf("triangle pos3:		%f\n", triangle->pos3.z);
	printf("triangle color_r:	%f\n", triangle->color.r);
	printf("triangle color_g:	%f\n", triangle->color.g);
	printf("triangle color_b:	%f\n", triangle->color.b);
	printf("\n");

	printf("pointers:\n");
	printf("pointer t_data:		%p\n", data);
	printf("pointer t_camera:	%p\n", camera);
	printf("pointer t_light:	%p\n", light);
	printf("pointer t_sphere:	%p\n", sphere);
	printf("pointer t_plane:	%p\n", plane);
	printf("pointer t_square:	%p\n", square);
	printf("pointer t_cylinder:	%p\n", cylinder);
	printf("pointer t_triangle:	%p\n", triangle);
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
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			print_error("Can't retrieve line");
		if (check_line(line) == false)
			parse_line(line, data);
		// 	break;	
		// if (*line != '#')
		free(line);
		line = NULL;
	}
	close (fd);
	loop_list_data(data);
}
