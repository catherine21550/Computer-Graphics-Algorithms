/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:40:02 by khuk              #+#    #+#             */
/*   Updated: 2024/06/16 20:54:45 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *my_stack)
{
	int	temp;

	if (my_stack->size <= 1 || my_stack->stack == NULL)
		return ;
	temp = my_stack->stack[0];
	my_stack->stack[0] = my_stack->stack[1];
	my_stack->stack[1] = temp;
}

void	ft_swap_a(t_stack *stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack *stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
