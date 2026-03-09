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

static void	ft_rotate(t_stack *my_stack)
{
	int	temp;
	int	i;

	temp = my_stack->stack[0];
	i = 0;
	while (i <= (my_stack->size - 1 - 1))
	{
		my_stack->stack[i] = my_stack->stack[i + 1];
		i++;
	}
	my_stack->stack[my_stack->size - 1] = temp;
}

void	ft_rotate_a(t_stack *stack_a)
{
	if (stack_a->size <= 0 || stack_a->stack == NULL)
		return ;
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack *stack_b)
{
	if (stack_b->size <= 0 || stack_b->stack == NULL)
		return ;
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 0 || !stack_a->stack || stack_b->size <= 0
		|| !stack_b->stack)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
