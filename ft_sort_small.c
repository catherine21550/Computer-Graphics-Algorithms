/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:32:14 by khuk              #+#    #+#             */
/*   Updated: 2024/06/23 17:39:33 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(int **arr, int *size)
{
		
	while (!is_sorted(arr, size))
	{
		if ((*arr)[0] < (*arr)[*size - 1])
			ft_rev_rotate_a(arr, size);
		else if (find_max_index(arr, size) == 0 && ft_is_sorted_after(arr, 1, *size - 1))
			ft_rotate_a(arr, size);
		else if ((*arr)[0] > (*arr)[1])
			ft_swap_a(*arr, *size);
		else
			ft_rotate_a(arr, size);
		for (int i = 0; i < *size; i++)
			ft_printf("%i\n", (*arr)[i]);
	}
}