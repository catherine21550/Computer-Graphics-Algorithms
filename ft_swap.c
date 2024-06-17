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

void	ft_swap(int *my_stack, int size)
{
	int	temp;

	if (size <= 1 || my_stack == NULL)
		return ;
	temp = my_stack[0];
	my_stack[0] = my_stack[1];
	my_stack[1] = temp;
}

void	ft_swap_a(int *my_stack, int size)
{
	ft_swap(my_stack, size);
	write(1, "sa\n", 3);
}

void	ft_swap_b(int *my_stack, int size)
{
	ft_swap(my_stack, size);
	write(1, "sb\n", 3);
}

void	ft_swap_ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	ft_swap(stack_a, size_a);
	ft_swap(stack_b, size_b);
	write(1, "ss\n", 3);
}
