/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:11:53 by khuk              #+#    #+#             */
/*   Updated: 2024/06/27 15:54:58 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midvalue(int *arr, int size)
{
	int		i;
	long	mid;

	i = 0;
	mid = 0;
	while (i <= (size - 1))
	{
		mid += arr[i];
		i++;
	}
	return (mid / size);
}

int	sort_in_two(int	*stack_a, int *stack_b, int size_a, int size_b)
{
	int	mid_a;

	while (*size_a > 4)
	{
		mid_a = find_midvalue(*stack_a, *size_a);
		if ((*stack_a)[0] < mid_a)
		{
			if (!ft_push_b(stack_b, stack_a, size_b, size_a))
				return (0);
		}
		else
		{
			if (!ft_rotate_a(stack_a, size_a))
				return (0);
		}
	}
	return (1);
}
