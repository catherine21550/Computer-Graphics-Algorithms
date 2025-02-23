/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:46 by khuk              #+#    #+#             */
/*   Updated: 2025/02/23 20:47:32 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

/* For visual representation */
/* void	print_square_map(t_game *m, t_scene *scene)
{
	int	y = 0;
	
	while (y < (int)scene->y_size)
	{
		int	x = 0;
		while (x < (int)scene->x_size)
		{
			printf("X:%f Y:%f, Type: %d, Color:%d\n", scene->coord[y][x].x,
					scene->coord[y][x].y, scene->coord[y][x].type, 
					scene->coord[y][x].color);
			x++;
		}
		y++;
	}
	printf("Player's location: x %f y %f\n", scene->player->x, scene->player->y);
	printf("Direction of player/scene: %f %f\n", scene->x_dir, scene->y_dir);
	printf("Plane of scene: %f %f\n", scene->x_plane, scene->y_plane);
	printf("bits_per_pixel: %d, size_line: %d, endian: %d\n", 
	m->img.bits_per_pixel, m->img.size_line, m->img.endian);
} */

void	rendering_prep_calculation(t_game *main, double *k,
		double *delta, t_dda *d)
{
	k[1] = cos(main->scene->angle * CUB_PI / 180) + main->scene->x_plane * k[0];
	k[2] = sin(main->scene->angle * CUB_PI / 180) + main->scene->y_plane * k[0];
	if (k[1] == 0)
		delta[0] = 1e30;
	else
		delta[0] = ft_abs(1 / k[1]);
	if (k[2] == 0)
		delta[1] = 1e30;
	else
		delta[1] = ft_abs(1 / k[2]);
	d->x_map = main->scene->player->x;
	d->y_map = main->scene->player->y;
}

void	draw_with_texture(t_game *main, t_dda *d, double *draw, double *k)
{
	t_img	*texture;

	texture = NULL;
	if (d->side == 0)
	{
		if (k[1] > 0)
			texture = &main->ea;
		else
			texture = &main->we;
		draw[3] = main->scene->player->y + k[3] * k[2];
	}
	else
	{
		if (k[2] > 0)
			texture = &main->so;
		else
			texture = &main->no;
		draw[3] = main->scene->player->x + k[3] * k[1];
	}
	draw[3] = draw[3] - (int)draw[3];
	draw_line(main, d->x, draw, texture);
}

// k[0] - ray_x_offset, х coordinate of the camera and position of player
// k[1] - raydir_x
// k[2] - raydir_y
// k[3] - perpWallDist
// rey[0] - dist of rey from one x side to another x side of square;
// rey[1] - same for y
// draw[2] - height of the line
void	rendering_process(t_game *main)
{
	double	k[4];
	double	delta_rey[2];
	double	draw[4];
	t_dda	d;

	d.x = -1;
	while (++d.x <= main->win_width)
	{
		k[0] = (2 * d.x / (double)main->win_width - 1);
		rendering_prep_calculation(main, k, delta_rey, &d);
		ft_dda(main, &d, delta_rey, k);
		if (d.side == 0)
			k[3] = d.x_dist_wall - delta_rey[0];
		else
			k[3] = d.y_dist_wall - delta_rey[1];
		draw[2] = main->win_height / k[3];
		draw[0] = fmax(0, (main->win_height / 2 - draw[2] / 2));
		draw[1] = fmin((main->win_height - 1),
				(main->win_height / 2 + draw[2] / 2));
		draw_with_texture(main, &d, draw, k);
	}
}

/* void draw_player(t_game *main)
{
    // Set the drawn height to one-fifth of the window height.
   // double player_height = main->win_height / 5;
    // Calculate scale factor based on the original texture height.
    //double scale = player_height / main->player.height;
    // Apply scale to the texture width.
   // double player_width = main->player.width * scale;
    // Compute horizontal starting position so that the sprite is centered.
   // double start_x = main->win_width / 2 - player_width / 2;
  //  double end_x = start_x + player_width;
    double x;

    // Loop over every x coordinate in the drawn sprite.
    for (x = start_x; x < end_x; x++) {
        // Determine the relative horizontal position (0.0 to 1.0)
        
        // Draw a vertical line at this x coordinate.
        // The vertical range is from (win_height - player_height) at the top,
        // to win_height at the bottom.
        // We pass tex_x (as line_param[3]) so that draw_line can pick the right column of the texture.
        draw_line(main, x, (double []){main->win_height - player_height, main->win_height, 0, tex_x}, &main->player);
    }
} */
void draw_scaled_image(t_game *main, t_img *texture, int *dest, int *target);

void	draw_player(t_game *main)
{
	double	player_height;
	double	player_width;
	double	draw[2];
	//double	x;

	player_height = main->win_height / 3;
	player_width = (player_height / main->player.height) * main->player.width;
	draw[0] = main->win_width / 2 - (player_width / 2) + main->win_width / 8;
	draw[1] = main->win_height - player_height;
	draw_scaled_image(main, &main->player, (int []){(int)draw[0], (int)draw[1]},
		(int []){(int)player_width, (int)player_height});
}

void	draw_img(t_game *main)
{
	solid_color(main, main->win_width, main->win_height);
	rendering_process(main);
	if (main->player.created)
		draw_player(main);
}

bool	create_main_img(t_game *main)
{
	main->img.img_ptr = mlx_new_image(main->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!main->img.img_ptr)
		return (ft_free_game(main), ft_putstr_fd(IMG_ER, 2), false);
	main->img.ptr_imgbit = mlx_get_data_addr(main->img.img_ptr,
			&main->img.bits_per_pixel, &main->img.size_line, &main->img.endian);
	if (!main->img.ptr_imgbit)
		return (ft_free_game(main),
				ft_putstr_fd("Error: mlx_get_data failed\n", 2), false);
	return (main->img.created = true);
}

bool	ft_init_mlx(t_game *main)
{
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		return (ft_free_game(main), ft_putstr_fd("Error: mlx_init failed\n", 2), false);
	main->win_ptr = mlx_new_window(main->mlx_ptr, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!main->win_ptr)
		return (ft_free_game(main),
				ft_putstr_fd("Error: mlx_new_window failed\n", 2), false);
	return (true);
}

bool	handle_graphics(t_game *main)
{
	scene_init(main);
	if (!ft_init_mlx(main) || !create_main_img(main))
		return (false);
	if (!get_all_textures(main))
		return (false);
	draw_img(main);
	mlx_put_image_to_window(main->mlx_ptr, main->win_ptr,
		main->img.img_ptr, 0, 0);
	mlx_hook(main->win_ptr, 17, (1L << 0), &exit_function, main);
	mlx_hook(main->win_ptr, 2, (1L << 0), &key_function, main);
	//mlx_hook(main->win_ptr, 6, (1L << 6), &mouse_move_function, NULL);
	mlx_loop(main->mlx_ptr);
	ft_free_game(main);
	return (true);
}
