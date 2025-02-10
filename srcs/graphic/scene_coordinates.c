/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:25:25 by khuk              #+#    #+#             */
/*   Updated: 2025/02/10 13:34:32 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

size_t	size_of_map_x(t_data *data)
{
	size_t	size;

	size = 0;
	while (data->map[0][size] && data->map[0][size] != '\n')
	{
			size++;
	}
	return (size);
}

static void	fill_coord_node(t_game *main, t_square *node, int j, int i)
{
	node->y = j;
	node->x = i;
	node->color = 0;
	if (main->data->map[j][i] == ' ' || main->data->map[j][i] == '\t')
	{
		node->type = NONE;
		node->color = main->data->ceiling;
	}
	else if (main->data->map[j][i] == '0')
	{
		node->type = FLOOR;
		node->color = main->data->floor;
	}
	else if (main->data->map[j][i] == '1')
		node->type = WALL;
	else if (main->data->map[j][i] == 'N')
	{
		node->type = PLAY;
		main->scene->player = node;
	}
	else
		node->type = SPRITE;
}

void	fill_coordinates(t_game *main)
{
	int	i;
	int	j;

	j = -1;
	main->scene = ft_calloc(sizeof(t_scene), 1);
	if (!main->scene)
		return (cleanup(main->data), exit_error("malloc failed\n"));
	main->scene->y_size = main->data->rows;
	main->scene->coord = ft_calloc(sizeof(t_square *), main->scene->y_size);
	if (!main->scene->coord)
		return (cleanup(main->data), free(main->scene), exit_error("malloc failed\n"));
	main->scene->x_size = size_of_map_x(main->data);
	while (++j < (int)main->scene->y_size)
	{
		main->scene->coord[j] = ft_calloc(sizeof(t_square), main->scene->x_size);
		if (!main->scene->coord[j])
			return (ft_free_coord(&main->scene, j), cleanup(main->data),
					exit_error("malloc failed\n"));
		i = 0;
		while (main->data->map[j][i] && main->data->map[j][i] != '\n')
		{
			fill_coord_node(main, &main->scene->coord[j][i], j, i);
			i++;
		}
	}
}
