/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:53:44 by khuk              #+#    #+#             */
/*   Updated: 2024/06/17 09:20:20 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rotate(t_stack *my_stack)
{
	int	temp;
	int	i;

	temp = my_stack->stack[my_stack->size - 1];
	i = my_stack->size - 1;
	while (i > 0)
	{
		my_stack->stack[i] = my_stack->stack[i - 1];
		i--;
	}
	my_stack->stack[0] = temp;
}

void	ft_rev_rotate_a(t_stack *stack_a)
{
	if (stack_a->size <= 0 || stack_a->stack == NULL)
		return ;
	ft_rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rev_rotate_b(t_stack *stack_b)
{
	if (stack_b->size <= 0 || stack_b->stack == NULL)
		return ;
	ft_rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rev_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 0 || !(stack_a->stack) || stack_b->size <= 0
		|| !(stack_b->stack))
		return ;
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
