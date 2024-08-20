/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:42:19 by khuk              #+#    #+#             */
/*   Updated: 2024/08/18 22:15:06 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* int	handle_key(int key, t_data *data, t_img *img)
{
	
	if (key == XK_Escape)
	{
		(void)img;
		ft_printf("Loop_end: %d\n", mlx_loop_end (data->mlx_ptr));
		return (1);
	}
	return (0);
} */

int	mouse_handling(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	if (button == 1)
		ft_printf("Left click\n");
	else
		ft_printf("Button %d was clicked\n", button);
	return (0);
}

void	print_data(t_img *data)
{
	ft_printf("In print data\n");
	ft_printf("Bits per pxl: %d\n Size line: %d\n Endian: %d\n", data->bits_per_pixel, data->size_line, data->endian);
	ft_printf("Hight: %d\n Width: %d\n", data->height, data->width);

}

void	my_put_pixel(t_img *img, int x, int y, int color)
{
	int		i;

	i = (img->size_line * y) + ((img->bits_per_pixel / 8) * x);
	*((unsigned int *)(i + img->ptr_imgbit)) = color;
}

void solid_color(t_img *img, int x, int y)
{
	int		i[2];

	i[0] = -1;
	while (++i[0] < y)
	{
		i[1] = -1;
		while (++i[1] < x)
			my_put_pixel(img, i[1], i[0], 0xFFFFFF);
	}
}
// i[0] - x, i[1] - y, i[2] - dx, i[3] -dy
// j[0] - incx, j[1] - incy new x = i[2], new y = i[3]
void	connect_dots(t_map **coord)
{
	int	i[5];
	int j[2];

	i[1] = 0;
	while (++i[1] < coord[1]->arrlen)
	{
		i[0] = 0;
		while (++i[0] < coord[1]->strlen)
		{
			i[2] = coord[1]->map[i[0]][i[1]] - coord[1]->map[i[0] - 1][i[1] - 1];
			i[3] = coord[2]->map[i[0]][i[1]] - coord[2]->map[i[0] - 1][i[1] - 1];
			i[4] = i[3];
			if (i[2] > i[3])
				i[4] = i[2];
		}
	}
}

void make_dots(t_data *data, int ac, char *av[])
{
	t_map	map[3];
	int		i[2];

	(void)data;
	if (! get_map(ac, av, &map[0]))
		return ;
	if (! get_map(ac, av, &map[1]))
		return ;
	if (! get_map(ac, av, &map[2]))
		return ;
	i[0] = -1;
	while (++i[0] < map[0].arrlen)
	{
		i[1] = -1;
		while (++i[1] < map[0].strlen)
		{
			//Not isometric
/* 			map[1].map[i[0]][i[1]] = i[1] + (cos(25) * map[0].map[i[0]][i[1]]);
			ft_printf("destination x: %d, ", map[1].map[i[0]][i[1]]);
			map[2].map[i[0]][i[1]] = i[0] + (sin(25) * map[0].map[i[0]][i[1]]);
			ft_printf("destination y: %d\n", map[2].map[i[0]][i[1]] ); */
			// Some isometric projections
/* 			ft_printf("Before calculation\n");
			map[1].map[i[0]][i[1]] = (i[1] * (cos(125))) + (i[0] * (cos(125 + 2))) + (map[0].map[i[0]][i[1]] * cos(125 - 2)) + 100;
			ft_printf("destination x: %d, ", map[1].map[i[0]][i[1]]);
			map[2].map[i[0]][i[1]] = (i[1] * (sin(125))) + (i[0] * (sin(125 + 2))) + (map[0].map[i[0]][i[1]] * sin(125 - 2)) + 80;
			ft_printf("destination y: %d\n", map[2].map[i[0]][i[1]] );
			my_put_pixel(&data->img, (map[1].map[i[0]][i[1]] * 5), (map[2].map[i[0]][i[1]] * 5), 0xFF0000); */
/* 			ft_printf("Before calculation\n");
			map[1].map[i[0]][i[1]] = (i[1] * (sqrt(2) / 2)) - (i[0] * (sqrt(2) / 2)) + 100;
			ft_printf("destination x: %d, ", map[1].map[i[0]][i[1]]);
			map[2].map[i[0]][i[1]] = (i[1] * (sqrt(2) / 2)) + (i[0] * (sqrt(2) / 2)) + (map[0].map[i[0]][i[1]] * (sqrt(2) / 2)) + 20;
			ft_printf("destination y: %d\n", map[2].map[i[0]][i[1]] );
			my_put_pixel(&data->img, (map[1].map[i[0]][i[1]] * 5), (map[2].map[i[0]][i[1]] * 5), 0x000000); */
			map[1].map[i[0]][i[1]] = i[1]  * cos(100) - map[0].map[i[0]][i[1]] * sin(100) * cos(100) + i[0] * sin(100)*sin(100) + 30;
			ft_printf("destination x: %d, ", map[1].map[i[0]][i[1]]);
			map[2].map[i[0]][i[1]] = i[1] * sin(100) + map[0].map[i[0]][i[1]] * cos(100)*cos(100) - i[0] * cos(100)*sin(100) + 20;
			ft_printf("destination y: %d\n", map[2].map[i[0]][i[1]] );
			my_put_pixel(&data->img, (map[1].map[i[0]][i[1]] * 10), (map[2].map[i[0]][i[1]] * 10), 0x000000);
		}
	}
	ft_printf("My x coordinates:\n");
	for(int i = 0; i < map[1].arrlen; i++)
	{
		for(int j = 0; j < map[1].strlen; j++)
			ft_printf("%d ", map[1].map[i][j]);
		ft_printf("\n");
	}
	ft_printf("My y coordinates:\n");
	for(int i = 0; i < map[2].arrlen; i++)
	{
		for(int j = 0; j < map[2].strlen; j++)
			ft_printf("%d ", map[2].map[i][j]);
		ft_printf("\n");
	}
	connect_dots(&map);
}

int	exit_function(t_data *data)
{
	mlx_loop_end (data->mlx_ptr);
	return (0);
}

int	key_function(int key, t_data *data)
{
	ft_printf("The key %d is pressed\n", key);
	if (key == XK_Escape)
		mlx_loop_end (data->mlx_ptr);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	data;
	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (-1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "FdF");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), -1);
	mlx_mouse_hook(data.win_ptr, &mouse_handling, &data);
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, 1000, 1000);
	data.img.ptr_imgbit = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.size_line, &data.img.endian);
	print_data(&data.img);
	solid_color(&data.img, 1000, 1000);
	make_dots(&data, ac, av);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
	//mlx_key_hook(data.win_ptr, &handle_key, &data);
	mlx_hook(data.win_ptr, 17, (1L<<0), &exit_function, &data);
	mlx_hook(data.win_ptr, 2, (1L<<0), &key_function, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	return (free(data.mlx_ptr), 0);
}
