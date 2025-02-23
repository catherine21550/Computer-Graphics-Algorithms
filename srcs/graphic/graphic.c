/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:46 by khuk              #+#    #+#             */
/*   Updated: 2025/02/23 23:12:22 by khuk             ###   ########.fr       */
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
void	draw_player(t_game *main)
{
	double	player_height;
	double	player_width;
	double	draw[2];

	player_height = main->win_height / 3;
	player_width = (player_height / main->player.height) * main->player.width;
	draw[0] = main->win_width / 2 - (player_width / 2) + main->win_width / 8;
	draw[1] = main->win_height - player_height;
	draw_scaled_image(main, &main->player, (int []){(int)draw[0], (int)draw[1]},
		(int []){(int)player_width, (int)player_height});
}

void	rendering_process(t_game *main)
{
	solid_color(main, main->win_width, main->win_height);
	draw_walls(main);
	if (main->player.created)
		draw_player(main);
}

bool	handle_graphics(t_game *main)
{
	scene_init(main);
	if (!ft_init_mlx(main) || !create_main_img(main))
		return (false);
	if (!get_all_textures(main))
		return (false);
	rendering_process(main);
	mlx_put_image_to_window(main->mlx_ptr, main->win_ptr,
		main->img.img_ptr, 0, 0);
	mlx_hook(main->win_ptr, 17, (1L << 0), &exit_function, main);
	mlx_hook(main->win_ptr, 2, (1L << 0), &key_function, main);
	//mlx_hook(main->win_ptr, 6, (1L << 6), &mouse_move_function, NULL);
	mlx_loop(main->mlx_ptr);
	ft_free_game(main);
	return (true);
}
