/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:46 by khuk              #+#    #+#             */
/*   Updated: 2025/02/15 23:36:12 by khuk             ###   ########.fr       */
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
	
	if (!main->img.ptr_imgbit)
	{
		fprintf(stderr, "Error: Image buffer is NULL\n");
		return ;//debug
	}
	if (x > main->img.width || y > main->img.height || x < 0 || y < 0)
		return ;
	i = (main->img.size_line * y) + ((main->img.bits_per_pixel / 8) * x);
	*((unsigned int *)(i + main->img.ptr_imgbit)) = color;
}

void	draw_line(t_game *main, double	x, double *line_param, int color)
{
	double	i;

	i = line_param[0] - 1;
	while (++i <= line_param[1])
	{
		my_put_pixel(main, x, i, color);
		i++;
	}
}

void	ft_dda_util(t_dda *d, double *delta, char c)
{
	if (c == 'x')
	{
		d->x_dist_wall = d->x_dist_wall + delta[0];
		d->x_map += d->x_step;
		d->side = 0;
	}
	else
	{
		d->y_dist_wall = d->y_dist_wall + delta[1];
		d->y_map += d->y_step;
		d->side = 1;
	}
}

void	ft_dda(t_game *main, t_dda *d, double *delta, double *k)
{
	if (k[1] >= 0)
	{
		d->x_dist_wall = (d->x_map + 1.0 - main->scene->player->x) * delta[0];
		d->x_step = 1;
	}
	else
	{
		d->x_dist_wall = (main->scene->player->x - d->x_map) * delta[0];
		d->x_step = -1;
	}
	if (k[2] >= 0)
	{
		d->y_dist_wall = (d->y_map + 1.0 - main->scene->player->y) * delta[1];
		d->y_step = 1;
	}
	else
	{
		d->y_dist_wall = (main->scene->player->y - d->y_map) * delta[1];
		d->y_step = -1;
	}
	// d->x_step = ft_sign_dda(k[1]);
	// d->y_step = ft_sign_dda(k[2]);
	d->side = 0;
	while (true)
	{
		if (d->x_dist_wall < d->y_dist_wall)
			ft_dda_util(d, delta, 'x');
		else
			ft_dda_util(d, delta, 'y');
		if (main->scene->coord[(int)d->y_map][(int)d->x_map].type != FLOOR)
			break ;
	}
}

void	rendering_prep_calculation(t_game *main, double *k, double *delta, t_dda *d)
{
		k[1] = main->scene->x_dir + main->scene->x_plane * k[0];
		k[2] = main->scene->y_dir + main->scene->y_plane * k[0];
		if (k[1] == 0)
			k[1] = 0.0001;
		if (k[2] == 0)
			k[2] = 0.0001;
		delta[0] = 0;
		delta[1] = 0;
		if (k[1] != 0)
			delta[0] = ft_abs(1 / k[1]);
		if (k[2] != 0)
			delta[1] = ft_abs(1 / k[2]);
		d->x_map = main->scene->player->x;
		d->y_map = main->scene->player->y;
}

// k[0] - ray_x_offset, х coordinate of the camera and position of player
// k[1] - raydir_x;
// k[2] - raydir_y;
// rey[0] - dist of rey from one x side to another x side of square;
// rey[1] - same for y.
bool	rendering_process(t_game *main)
{
	double	k[4];
	double	delta_rey[2];
	int		x;
	t_dda	d;

	x = -1;
	main->img.width = main->win_width;
	main->img.height = main->win_height;
	while (++x <= main->win_width)
	{
		// prep calculation
		k[0] = (double)(2 * x / (double)main->win_width - 1);
		rendering_prep_calculation(main, k, delta_rey, &d);
		// DDA algorithm
		ft_dda(main, &d, delta_rey, k);
		// calculation of perpWallDist(fisheye)
		
		if (d.side == 0)
			k[3] = (d.x_map - main->scene->player->x + (1 - d.x_step) / 2) / k[1];
		else
			k[3] = (d.y_map - main->scene->player->y + (1 - d.y_step) / 2) / k[1];
		// determining the line height (lineHeight)
		double	vert_line = main->win_height / k[3];
		// determining the color/texture
		/* Якщо side == 0:
		color = базовий колір стіни
		Якщо крок по X негативний (дивимося вліво), затемнюємо колір
		Інакше:
		color = базовий колір стіни
		Затемнюємо колір, бо це горизонтальна стіна.
		Якщо використовувати текстури:
		Визначаємо точку удару (wall_x).
		Визначаємо текстурний індекс (tex_x).
		Беремо піксель із текстури. */
		// Drawing the line
		double	draw[2];
		draw[0] = fmax(0, (main->win_height / 2 - vert_line / 2));
		draw[1] = fmin((main->win_height - 1), (main->win_height / 2 + vert_line / 2));
		printf("x = %d, k[0] = %f, k[1] = %f, k[2] = %f, k[3] = %f\n draw[0] = %f, draw[1] = %f\n", x, k[0], k[1], k[2], k[3], draw[0], draw[1]);
		draw_line(main, x, draw, 0x000000); // Or another drawing function
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
	main->img.img_ptr = mlx_new_image(main->mlx_ptr, main->win_width, main->win_height);
	if (!main->img.img_ptr)
		return (fprintf(stderr, "Error: Failed to create new image\n"), (void)0);//protect if fails
	main->img.ptr_imgbit = mlx_get_data_addr(main->img.img_ptr,
			&main->img.bits_per_pixel, &main->img.size_line, &main->img.endian);
	if (!main->img.ptr_imgbit)
		return ;//protect if fails
	print_square_map(main->scene);//temp
	rendering_process(main);
	mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->img.img_ptr, 0, 0);
	mlx_hook(main->win_ptr, 17, (1L << 0), &exit_function, main);
	mlx_hook(main->win_ptr, 2, (1L << 0), &key_function, main);
	mlx_hook(main->win_ptr, 6, (1L << 6), &mouse_move_function, NULL);
	mlx_loop(main->mlx_ptr);
	destroy_graphics(main);
}
