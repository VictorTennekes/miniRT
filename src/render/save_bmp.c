/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_bmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:16:27 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/06/03 13:16:27 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	A collection of functions to fill a buffer with the correct data for a
**	bitmap image.
**
**	source: https://bit.ly/2UgVX5o
*/

#include <minirt.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static size_t	bmp_size(t_data *data)
{
	size_t	res;

	res = 54;
	res += 3 * (data->window.y * ((data->window.x * 3) % 4 == 0 ?
		data->window.x : data->window.x + 4 - ((data->window.x * 3) % 4)));
	return (res);
}

static void		bmp_file_header(char *buf, size_t file_size)
{
	*((uint8_t *)&buf[0]) = (uint8_t)0x42;
	*((uint8_t *)&buf[1]) = (uint8_t)0x4D;
	*((uint32_t *)&buf[2]) = (uint32_t)file_size;
	*((uint32_t *)&buf[10]) = (uint32_t)0x36;
}

static void		bmp_info_header(char *buf, t_data *data)
{
	*((uint32_t *)&buf[14]) = (uint32_t)0x28;
	*((uint32_t *)&buf[18]) = (uint32_t)data->window.x;
	*((uint32_t *)&buf[22]) = (uint32_t)data->window.y;
	*((uint16_t *)&buf[26]) = (uint16_t)0x01;
	*((uint16_t *)&buf[28]) = (uint16_t)0x18;
}

static void		bmp_write_image(char *buf, t_data *data)
{
	uint32_t	index;
	t_color		color;
	t_color		*frame;
	int			x;
	int			y;

	index = 54;
	frame = get_frame(data);
	y = data->window.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->window.x)
		{
			color = frame[x * data->window.y + y];
			buf[index + 0] = color.b;
			buf[index + 1] = color.g;
			buf[index + 2] = color.r;
			index += 3;
			x++;
		}
		if ((data->window.x * 3) % 4 != 0)
			index += 4 - (data->window.x * 3) % 4;
		y--;
	}
}

void			save_bmp(t_data *data)
{
	char	*buf;
	int		fd;
	size_t	file_size;

	fd = open("scene.bmp", O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		print_error("Failed to open/create the bmp file", data);
	file_size = bmp_size(data);
	buf = ft_calloc(1, file_size);
	bmp_file_header(buf, file_size);
	bmp_info_header(buf, data);
	bmp_write_image(buf, data);
	if (write(fd, buf, file_size) < 0)
		print_error("Failed to write to bmp file", data);
	if (close(fd) < 0)
		print_error("Failed to close bmp file", data);
	free(buf);
}
