/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:46:47 by vtenneke       #+#    #+#                */
/*   Updated: 2020/01/23 16:56:31 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}				t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void			my_grid_put_center(t_data img, int x, int y, int color, int screen_x, int screen_y, int gap_size)
{
	int max_x = (screen_x / 2) + (screen_x / 8);
	int max_y = (screen_y / 2) + (screen_x / 8);
	int min_x = (screen_x / 2) - (screen_x / 8);
	int min_y = (screen_y / 2) - (screen_x / 8);

	printf("max_x: %i\n max_y: %i\n min_x: %i\n min_y %i\n", max_x, max_y, min_x, min_y);
	while (x != max_x)
	{
		y = min_y;
		while (y != max_y && (x % gap_size) == 0)
		{
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		x++;
	}
	while (y != max_y)
	{
		x = min_x;
		while (x != max_x && (y % gap_size) == 0)
		{
			my_mlx_pixel_put(&img, x, y, color);
			x++;
		}
		y++;
	}
	x = max_x;
	y = min_y;
	while (y <= max_y)
	{
		my_mlx_pixel_put(&img, x, y, color);
		y++;
	}
	y = max_y;
	x = min_x;
	while (x <= max_x)
	{
		my_mlx_pixel_put(&img, x, y, color);
		x++;
	}
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
	int x = 715;
	int y = 295;
	int screen_x = 1920;
	int screen_y = 1080;
	
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, screen_x, screen_y, "Hello world!");
    img.img = mlx_new_image(mlx, screen_x, screen_y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	my_grid_put_center(img, x, y, 0xFFFFFF, screen_x, screen_y, 20);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
