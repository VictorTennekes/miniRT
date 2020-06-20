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

	res = 14;
	res += 40;
	res += 3 * (data->window.x * data->window.y);
	// res += ((data->window.x * 3) % 4) ? data->window.y * (4 - ((data->window.x * 3) % 4)) : 0;
	return (res);
}

static void		bmp_file_header(char *buf, size_t file_size)
{
	*((uint16_t *)&buf[0x00]) = (uint16_t)0x4d42;
	*((uint32_t *)&buf[0x02]) = (uint32_t)file_size;
	*((uint32_t *)&buf[0x0A]) = (uint32_t)0x36;
}

static void		bmp_info_header(char *buf, t_data *data)
{
	*((uint32_t *)&buf[0x0E]) = (uint32_t)40;
	*((uint32_t *)&buf[0x12]) = (uint32_t)data->window.x;
	*((uint32_t *)&buf[0x16]) = (uint32_t)data->window.y;
	*((uint8_t *)&buf[0x1A]) = (uint8_t)1;
	*((uint8_t *)&buf[0x1C]) = (uint8_t)24;
}

static void		bmp_write_image(char *buf, t_data *data)
{
	uint32_t	index;
	t_color		color;
	t_color		*frame;
	uint32_t	x;
	uint32_t	y;

	index = 0x36;
	frame = get_frame(data);
	y = data->window.y - 1;
	while (y > 0)
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
		y--;
	}
}

void			save_bmp(t_data *data)
{
	char	*buf;
	int		fd;
	int		tmp;
	size_t	file_size;

	fd = open("scene.bmp", O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		print_error("Failed to open/create the bmp file", data);
	tmp = data->window.x;
	if ((data->window.x * 3) % 4 != 0)
		data->window.x = data->window.x + ((data->window.x * 3) % 4);
	file_size = bmp_size(data);
	buf = malloc(file_size);
	bmp_file_header(buf, file_size);
	bmp_info_header(buf, data);
	bmp_write_image(buf, data);
	data->window.x = tmp;
	if (write(fd, buf, file_size) < 0)
		print_error("Failed to write to bmp file", data);
	if (close(fd) < 0)
		print_error("Failed to close bmp file", data);
	free(buf);
}
