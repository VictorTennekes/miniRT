/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:13:01 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/31 16:18:02 by vtenneke      ########   odam.nl         */
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
		printf("parse triangle\n");
}

void	loop_list_data(t_data *data)
{
	t_camera	*camera;
	t_light		*light;
	t_object	*sphere;
	t_object	*plane;
	t_object	*square;
	t_object	*cylinder;

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

	printf("screen res_x: %u\n", data->window.x);
	printf("screen res_y: %u\n", data->window.y);
	printf("res_set: %s\n", data->window.res_set?"true":"false");
	printf("\n");

	printf("map save: %s\n", data->mapinfo.save?"true":"false");
	printf("map amb_ratio: %f\n", data->mapinfo.amb_ratio);
	printf("map amb_color_r: %u\n", data->mapinfo.amb_color.r);
	printf("map amb_color_g: %u\n", data->mapinfo.amb_color.g);
	printf("map amb_color_b: %u\n", data->mapinfo.amb_color.b);
	printf("map amb_set: %s\n", data->mapinfo.amb_set?"true":"false");
	printf("\n");
	
	printf("camera fov: %i\n", camera->fov);
	printf("camera pos_x: %f\n", camera->pos.x);
	printf("camera pos_y: %f\n", camera->pos.y);
	printf("camera pos_z: %f\n", camera->pos.z);
	printf("\n");

	printf("light ratio: %f\n", light->ratio);
	printf("light pos_x: %f\n", light->pos.x);
	printf("light pos_y: %f\n", light->pos.y);
	printf("light pos_z: %f\n", light->pos.z);
	printf("light color_r: %u\n", light->color.r);
	printf("light color_g: %u\n", light->color.g);
	printf("light color_b: %u\n", light->color.b);
	printf("\n");

	printf("sphere size: %f\n", sphere->size);
	printf("sphere pos_x: %f\n", sphere->pos.x);
	printf("sphere pos_y: %f\n", sphere->pos.y);
	printf("sphere pos_z: %f\n", sphere->pos.z);
	printf("sphere color_r: %u\n", sphere->color.r);
	printf("sphere color_g: %u\n", sphere->color.g);
	printf("sphere color_b: %u\n", sphere->color.b);
	printf("\n");

	printf("plane pos_x: %f\n", plane->pos.x);
	printf("plane pos_y: %f\n", plane->pos.y);
	printf("plane pos_z: %f\n", plane->pos.z);
	printf("plane vector_x: %f\n", plane->vector.x);
	printf("plane vector_y: %f\n", plane->vector.y);
	printf("plane vector_z: %f\n", plane->vector.z);
	printf("plane color_r: %u\n", plane->color.r);
	printf("plane color_g: %u\n", plane->color.g);
	printf("plane color_b: %u\n", plane->color.b);
	printf("\n");

	printf("square pos_x: %f\n", square->pos.x);
	printf("square pos_y: %f\n", square->pos.y);
	printf("square pos_z: %f\n", square->pos.z);
	printf("square vector_x: %f\n", square->vector.x);
	printf("square vector_y: %f\n", square->vector.y);
	printf("square vector_z: %f\n", square->vector.z);
	printf("square size: %f\n", square->size);
	printf("square color_r: %u\n", square->color.r);
	printf("square color_g: %u\n", square->color.g);
	printf("square color_b: %u\n", square->color.b);
	printf("\n");

	printf("cylinder pos_x: %f\n", cylinder->pos.x);
	printf("cylinder pos_y: %f\n", cylinder->pos.y);
	printf("cylinder pos_z: %f\n", cylinder->pos.z);
	printf("cylinder vector_x: %f\n", cylinder->vector.x);
	printf("cylinder vector_y: %f\n", cylinder->vector.y);
	printf("cylinder vector_z: %f\n", cylinder->vector.z);
	printf("cylinder size: %f\n", cylinder->size);
	printf("cylinder height: %f\n", cylinder->height);
	printf("cylinder color_r: %u\n", cylinder->color.r);
	printf("cylinder color_g: %u\n", cylinder->color.g);
	printf("cylinder color_b: %u\n", cylinder->color.b);
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
	loop_list_data(data);
}
