/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:42:19 by khuk              #+#    #+#             */
/*   Updated: 2024/08/12 16:50:53 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
}	t_data;

int	handle_key(int key, t_data *data)
{
	ft_printf("The key %d is pressed\n", key);
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		return (free(data->mlx_ptr), 1);
	}
	return (0);
}

int	main()
{
//	void	*connection;
//	void	*my_window;
	t_data	my_data;

	my_data.mlx_ptr = mlx_init ();
	if (!my_data.mlx_ptr)
		return (-1);
	my_data.win_ptr = mlx_new_window(my_data.mlx_ptr, 250, 250, "FdF");
	if (!my_data.win_ptr)
	{
		mlx_destroy_window(my_data.mlx_ptr, my_data.win_ptr);
		return (free(my_data.mlx_ptr), -1);
	}
//	mlx_mouse_hook(my_window, );
//	mlx_string_put(connection, my_window, 10, 25, 225, "Fdf");
	mlx_key_hook(my_data.win_ptr, &handle_key, &my_data);
//	while (1)
//		;
	mlx_loop(my_data.mlx_ptr);
	mlx_destroy_window(my_data.mlx_ptr, my_data.win_ptr);
	mlx_destroy_display(my_data.mlx_ptr);
	return (0);
}
