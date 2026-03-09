/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_in_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:11:53 by khuk              #+#    #+#             */
/*   Updated: 2024/07/11 00:05:28 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midvalue(int *arr, int size)
{
	int			i;
	long		mid_2;
	long long	mid;

	i = 0;
	mid = 0;
	while (i <= (size - 1))
	{
		mid += arr[i];
		i++;
	}
	mid_2 = (int)(mid / size);
	return (mid_2);
}

void	sort_in_two(t_stack	*stack_a, t_stack *stack_b)
{
	int	mid_a;

	while (stack_a->size > 4)
	{
		mid_a = find_midvalue(stack_a->stack, stack_a->size);
		if (stack_a->stack[0] < mid_a)
			ft_push_b(stack_a, stack_b);
		else
			ft_rotate_a(stack_a);
	}
}
