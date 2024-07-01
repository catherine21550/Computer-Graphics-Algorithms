/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:32:14 by khuk              #+#    #+#             */
/*   Updated: 2024/07/01 11:55:48 by khuk             ###   ########.fr       */
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

int	push_min_four(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	i_min;

	i_min = find_min_index(arr_a, size_a);
	if (i_min == 0)
	{
		if (!ft_push_b(arr_b, arr_a, size_b, size_a))
			return (ft_free(arr_b), ft_free(arr_a), 0);
	}
	else if (i_min == 1)
	{
		ft_rotate_a(arr_a, size_a);
		if (!ft_push_b(arr_b, arr_a, size_b, size_a))
			return (ft_free(arr_b), ft_free(arr_a), 0);
	}
	else if (i_min == 2)
	{
		ft_rev_rotate_a(arr_a, size_a);
		ft_rev_rotate_a(arr_a, size_a);
		if (!ft_push_b(arr_b, arr_a, size_b, size_a))
			return (ft_free(arr_b), ft_free(arr_a), 0);
	}
	return (1);
}

int	sort_four(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	i_min;

	i_min = find_min_index(arr_a, size_a);
	if (i_min == 0 || i_min == 1 || i_min == 2)
	{
		if (!push_min_four(arr_a, arr_b, size_a, size_b))
			return (ft_free(arr_b), ft_free(arr_a), 0);
	}
	else
	{
		ft_rev_rotate_a(arr_a, size_a);
		if (!ft_push_b(arr_b, arr_a, size_b, size_a))
			return (ft_free(arr_b), ft_free(arr_a), 0);
	}
	sort_three(arr_a, size_a);
	if (!ft_push_a(arr_a, arr_b, size_a, size_b))
		return (ft_free(arr_b), ft_free(arr_a), 0);
	return (1);
}

int	sort_small(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (is_sorted(arr_a, size_a))
		return (1);
	else if (*size_a == 2)
	{
		if ((*arr_a)[0] > (*arr_a)[1])
			ft_swap_a(*arr_a, *size_a);
	}
	else if (*size_a == 3)
		sort_three(arr_a, size_a);
	else if (*size_a == 4)
	{
		if (!sort_four(arr_a, arr_b, size_a, size_b))
			return (ft_free(arr_b), ft_free(arr_a), 0);
	}
	else
		sort_five(arr_a, size_a);
	return (1);
}
