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

void	sort_five(int **arr, int *size)
{
		
	while (!is_sorted(arr, size))
	{
		if ((*arr)[0] < (*arr)[*size - 1])
			ft_rev_rotate_a(arr, size);
		else if (find_max_index(arr, size) == 0 
				&& ft_is_sorted_after(arr, 1, *size - 1))
			ft_rotate_a(arr, size);
		else if ((*arr)[0] > (*arr)[1])
			ft_swap_a(*arr, *size);
		else
			ft_rotate_a(arr, size);
		/* for (int i = 0; i < *size; i++)
			ft_printf("%i\n", (*arr)[i]); */
	}
}

void	sort_three(int **arr, int *size)
{
	if ((*arr)[0] > (*arr)[1] && (*arr)[0] > (*arr)[2] 
		&& (*arr)[1] > (*arr)[2])
	{
		ft_swap_a(*arr, *size);
		ft_rev_rotate_a(arr, size);
	}
	else if ((*arr)[1] > (*arr)[0] && (*arr)[1] > (*arr)[2] 
			&& (*arr)[0] > (*arr)[2])
		ft_rev_rotate_a(arr, size);
	else if ((*arr)[1] > (*arr)[0] && (*arr)[1] > (*arr)[2] 
			&& (*arr)[0] < (*arr)[2])
	{
		ft_swap_a(*arr, *size);
		ft_rotate_a(arr, size);
	}
	else if ((*arr)[0] > (*arr)[1] && (*arr)[0] > (*arr)[2] 
			&& (*arr)[1] < (*arr)[2])
		ft_rotate_a(arr, size);
	else if ((*arr)[2] > (*arr)[1] && (*arr)[2] > (*arr)[0] 
			&& (*arr)[1] < (*arr)[0])
		ft_swap_a(*arr, *size);
	else
		return ;
}

void	sort_four(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	i_min;

	i_min = find_min_index(arr_a, size_a);
	if (i_min == 0)
		ft_push_b(arr_b, arr_a, size_b, size_a);
	else if (i_min == 1)
	{
		ft_rotate_a(arr_a, size_a);
		ft_push_b(arr_b, arr_a, size_b, size_a);
	}
	else if (i_min == 2)
	{
		ft_rev_rotate_a(arr_a, size_a);
		ft_rev_rotate_a(arr_a, size_a);
		ft_push_b(arr_b, arr_a, size_b, size_a);
	}
	else 
	{
		ft_rev_rotate_a(arr_a, size_a);
		ft_push_b(arr_b, arr_a, size_b, size_a);
	}
	sort_three(arr_a, size_a);
	ft_push_a(arr_a, arr_b, size_a, size_b);
}

void	sort_small(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (is_sorted(arr_a, size_a))
		return ;
	
	else if (*size_a == 2)
	{
		if ((*arr_a)[0] > (*arr_a)[1])
			ft_swap_a(*arr_a, *size_a);
	}
	else if (*size_a == 3)
		sort_three(arr_a, size_a);
	else if (*size_a == 4)
		sort_four(arr_a, arr_b, size_a, size_b);
	else
		sort_five(arr_a, size_a);
}