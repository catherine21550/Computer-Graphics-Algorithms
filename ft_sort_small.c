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

void	sort_three(t_stack *stack_a)
{
	if (stack_a->stack[0] > stack_a->stack[1] && stack_a->stack[0]
		> stack_a->stack[2] && stack_a->stack[1] > stack_a->stack[2])
	{
		ft_swap_a(stack_a);
		ft_rev_rotate_a(stack_a);
	}
	else if (stack_a->stack[1] > stack_a->stack[0] && stack_a->stack[1]
		> stack_a->stack[2] && stack_a->stack[0] > stack_a->stack[2])
		ft_rev_rotate_a(stack_a);
	else if (stack_a->stack[1] > stack_a->stack[0] && stack_a->stack[1]
		> stack_a->stack[2] && stack_a->stack[0] < stack_a->stack[2])
	{
		ft_swap_a(stack_a);
		ft_rotate_a(stack_a);
	}
	else if (stack_a->stack[0] > stack_a->stack[1] && stack_a->stack[0]
		> stack_a->stack[2] && stack_a->stack[1] < stack_a->stack[2])
		ft_rotate_a(stack_a);
	else if (stack_a->stack[2] > stack_a->stack[1] && stack_a->stack[2]
		> stack_a->stack[0] && stack_a->stack[1] < stack_a->stack[0])
		ft_swap_a(stack_a);
	else
		return ;
}

static void	push_min_four(t_stack *stack_a, t_stack *stack_b)
{
	int	i_min;

	i_min = find_min_index(&stack_a->stack, &stack_a->size);
	if (i_min == 0)
		ft_push_b(stack_a, stack_b);
	else if (i_min == 1)
	{
		ft_rotate_a(stack_a);
		ft_push_b(stack_a, stack_b);
	}
	else if (i_min == 2)
	{
		ft_rev_rotate_a(stack_a);
		ft_rev_rotate_a(stack_a);
		ft_push_b(stack_a, stack_b);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	i_min;

	i_min = find_min_index(&stack_a->stack, &stack_a->size);
	if (i_min == 0 || i_min == 1 || i_min == 2)
		push_min_four(stack_a, stack_b);
	else
	{
		ft_rev_rotate_a(stack_a);
		ft_push_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	ft_push_a(stack_a, stack_b);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->stack[0] > stack_a->stack[1])
			ft_swap_a(stack_a);
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
}

/* void	sort_five(int **arr, int *size)
{
	while (!is_sorted(stack_a))
	{
		if (stack_a->stack[0] < stack_a->stack[*size - 1])
			ft_rev_rotate_a(stack_a);
		else if (find_max_index(stack_a) == 0
			&& ft_is_sorted_after(arr, 1, *size - 1))
			ft_rotate_a(stack_a);
		else if (stack_a->stack[0] > stack_a->stack[1])
			ft_swap_a(stack_a);
		else
			ft_rotate_a(stack_a);
	}
}
 */