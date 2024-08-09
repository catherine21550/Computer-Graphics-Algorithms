/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:42:19 by khuk              #+#    #+#             */
/*   Updated: 2024/08/09 18:57:02 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main()
{
	void	*connection;
	void	*my_window;

	connection = mlx_init ();
	if (!connection)
		return (-1);
	my_window = mlx_new_window(connection, 250, 250, "FdF");
	if (!my_window)
	{
		mlx_destroy_window(connection, my_window);
		return (free(connection), -1);
	}
	while (1)
		;
	mlx_loop(my_window);
//	mlx_mouse_hook(my_window, );
	mlx_string_put(connection, my_window, 10, 25, 225, "Fdf");
	mlx_destroy_window(connection, my_window);
	mlx_destroy_display(connection);
	return (0);
}
