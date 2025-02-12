/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:46 by khuk              #+#    #+#             */
/*   Updated: 2025/02/12 21:29:22 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphic.h"

/* For visual representation */
void	print_square_map(t_scene *scene)
{
	int	y = 0;
	
	while (y < (int)scene->y_size)
	{
		int	x = 0;
		while (x < (int)scene->x_size)
		{
			printf("X:%f Y:%f, Type: %d, Color:%d\n", scene->coord[y][x].x,
					scene->coord[y][x].y, scene->coord[y][x].type, scene->coord[y][x].color);
			x++;
		}
		y++;
	}
	printf("Player's location: x %f y %f\n", scene->player->x, scene->player->y);
	printf("Direction of player/scene: %f %f\n", scene->x_dir, scene->y_dir);
	printf("Plane of scene: %f %f\n", scene->x_plane, scene->y_plane);

}

void	my_put_pixel(t_game *main, int x, int y, int color)
{
	int		i;
	
	color = 0xFFFF00;
	if (!main->img.ptr_imgbit)
	{
		fprintf(stderr, "Error: Image buffer is NULL\n");
		return;
	}
	if (x > main->img.width || y > main->img.height || x < 0 || y < 0)
		return ;
	i = (main->img.size_line * y) + ((main->img.bits_per_pixel / 8) * x);
	fprintf(stderr, "Writing pixel at index: %d (x: %d, y: %d), buffer address: %p\n",
	        i, x, y, main->img.ptr_imgbit);
	*((unsigned int *)(i + main->img.ptr_imgbit)) = color;
}

void	draw_line(t_game *main, int x, int y, int linehight, int color)
{
	int	i[2];

	i[0] = -1;
	i[1] = y;
	while (++i[0] < linehight)
	{
		my_put_pixel(main, x, i[1], color);
		i[1]++;
	}
}
// k[0] - ray_x_offset;
// k[1] - raydir_x;
// k[2] - raydir_y;
// rey[0] - dist of rey from one x side to another x side of square;
// rey[1] - same for y.
bool	rendering_process(t_game *main)
{
	double	k[3];
	double	rey[2];
	int		x;

	main->img.img_ptr = mlx_new_image(main->mlx_ptr, main->win_width, main->win_height);
	if (!main->img.img_ptr)
		return (fprintf(stderr, "Error: Failed to create new image\n"), false);//protect if fails
	main->img.ptr_imgbit = mlx_get_data_addr(main->img.img_ptr,
			&main->img.bits_per_pixel, &main->img.size_line, &main->img.endian);
	if (!main->img.ptr_imgbit)
		return (false);//protect if fails
	x = -1;
	main->img.width = main->win_width;
	main->img.height = main->win_height;
	while (++x <= main->win_width)
	{
		// prep calculation
		k[0] = (double)(2 * x / main->win_width - 1);
		k[1] = main->scene->x_dir + main->scene->x_plane * k[0];
		k[2] = main->scene->y_dir + main->scene->y_plane * k[0];
		rey[0] = 0;
		rey[1] = 0;
		if (k[1] != 0)
			rey[0] = ft_abs(1 / k[1]);
		if (k[2] != 0)
			rey[1] = ft_abs(1 / k[2]);
		// DDA algorithm
		// calculation of perpWallDist
		// determining the line height (lineHeight)
		// determining the color/texture
		// Drawing the line
		draw_line(main, x, 0, 10, 0xFFFFFF); // Or another drawing function
	}
	return (true);
}

void	handle_graphics(t_game *main)
{
	scene_init(main);
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		return (cleanup(main->data), exit_error("mlx_init failed\n"));
	main->win_ptr = mlx_new_window(main->mlx_ptr, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!main->win_ptr)
		return (cleanup(main->data), exit_error("mlx_new_window failed\n"));
	print_square_map(main->scene);//temp
	rendering_process(main);
	mlx_hook(main->win_ptr, 17, (1L << 0), &exit_function, main);
	mlx_hook(main->win_ptr, 2, (1L << 0), &key_function, main);
	mlx_hook(main->win_ptr, 6, (1L << 6), &mouse_move_function, NULL);
	mlx_loop(main->mlx_ptr);
	destroy_graphics(main);
}
