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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

int	handle_key(int key, t_data *data, t_img *img)
{
	ft_printf("The key %d is pressed\n", key);
	if (key == XK_Escape)
	{
		(void)img;
		//mlx_destroy_image(data->mlx_ptr, img->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		return (free(data->mlx_ptr), 1);
	}
	return (0);
}

int	mouse_handling(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	if (button == 1)
		ft_printf("Left click\n");
	else
		ft_printf("Other click\n");
	return (0);
}

void	print_data(t_img *data)
{
	ft_printf("In print data\n");
	ft_printf("Bits per pxl: %d\n Size line: %d\n Endian: %d\n", data->bits_per_pixel, data->size_line, data->endian);
}

void	my_put_pixel(t_img *img, int x, int y, int colour)
{
	int	offset;

	offset = (img->size_line * y) + ((img->bits_per_pixel / 8) * x);
	*((unsigned int *)(offset + img->ptr_imgbit)) = colour;
}

int	main()
{
	t_data	my_data;
	t_img	img;
	int		i[2];

	my_data.mlx_ptr = mlx_init();
	if (!my_data.mlx_ptr)
		return (-1);
	my_data.win_ptr = mlx_new_window(my_data.mlx_ptr, 630, 250, "FdF");
	if (!my_data.win_ptr)
	{
		mlx_destroy_window(my_data.mlx_ptr, my_data.win_ptr);
		return (free(my_data.mlx_ptr), -1);
	}
	mlx_mouse_hook(my_data.win_ptr, &mouse_handling, &my_data);
	img.img_ptr = mlx_new_image(my_data.mlx_ptr, 630, 250);
	img.ptr_imgbit = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	print_data(&img);
	i[0] = -1;
	while (++i[0] < 250)
	{
		i[1] = -1;
		while (++i[1] < 630)
			my_put_pixel(&img, i[1], i[0], 0xFFFFFF);

	}
	mlx_put_image_to_window(my_data.mlx_ptr, my_data.win_ptr, img.img_ptr, 0, 0);
	mlx_key_hook(my_data.win_ptr, &handle_key, &my_data);
	mlx_loop(my_data.mlx_ptr);
/* 	mlx_destroy_image(my_data.mlx_ptr, img.img_ptr);
	mlx_destroy_window(my_data.mlx_ptr, my_data.win_ptr);
	mlx_destroy_display(my_data.win_ptr); */
	return (0);
}
