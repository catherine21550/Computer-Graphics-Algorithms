/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:46 by khuk              #+#    #+#             */
/*   Updated: 2025/02/10 13:33:30 by khuk             ###   ########.fr       */
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
			printf("X:%d Y:%d, Type: %d, Color:%d\n", scene->coord[y][x].x,
					scene->coord[y][x].y, scene->coord[y][x].type, scene->coord[y][x].color);
			x++;
		}
		y++;
	}
}

void	handle_graphics(t_game *main)
{
	fill_coordinates(main);
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		return (cleanup(main->data), exit_error("mlx_init failed\n"));
	main->win_ptr = mlx_new_window(main->mlx_ptr, W_WIDTH, W_HEIGHT, "Cub3D");
	if (!main->win_ptr)
		return (cleanup(main->data), exit_error("mlx_new_window failed\n"));
	print_square_map(main->scene);//temp
	mlx_hook(main->win_ptr, 17, (1L << 0), &exit_function, main);
	mlx_hook(main->win_ptr, 2, (1L << 0), &key_function, main);
	mlx_hook(main->win_ptr, 6, (1L << 6), &mouse_move_function, NULL);
	mlx_loop(main->mlx_ptr);
	destroy_graphics(main);
}
