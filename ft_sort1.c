/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:11:53 by khuk              #+#    #+#             */
/*   Updated: 2024/06/18 19:21:39 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int **arr, int *size)
{
	int min;
	int	i;

	min = (*arr)[0];
	i = 1;
	while (i < (*size - 1))
	{
		if (min > (*arr)[i])
			min = (*arr)[i];
		i++;
	}
	return (min);
}

int find_min_index(int **arr, int *size)
{
    int min;
    int i;

	i = 0;
    min = (*arr)[i];
    while (i < (*size - 1))
    {
        if (min > (*arr)[i])
            min = (*arr)[i];
        i++;
    }
    return (i);
}

int	ft_sort1(int **stack, int *size)
{
	int	index_min;
	int	i;
	int	*stack_b = NULL;
	int	size_b;

	size_b = 0;
	if ((*stack)[0] > (*stack)[1])
		ft_swap_a(*stack, *size);
	while ((*stack)[0] > (*stack)[*size - 1])
		ft_rev_rotate_a(stack, size);
	index_min = find_min_index(stack, size);
	if (index_min == 0)
		ft_push_a(stack, &stack_b, size, &size_b);
	if (index_min < (*size / 2))
	{
		i = index_min;
		while (i > 0)
		{
			ft_rotate_a(stack, size);
			i--;
		}
	}
	else
	{
		i = *size - index_min;
        while (i > 0)
		{
            ft_rev_rotate_a(stack, size);
            i--;
        }
	}
	return (1);
}
