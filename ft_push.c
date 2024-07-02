/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:39:21 by khuk              #+#    #+#             */
/*   Updated: 2024/06/16 20:54:25 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	stack_a->size = stack_a->size + 1;
	i = stack_a->size - 1 + 1;
	while (i > 0)
	{
		stack_a->stack[i + 1] = stack_a->stack[i];
		i--;
	}
	stack_a->stack[0] = stack_b->stack[0];
	i = 0;
	while (i <= (stack_b->size - 2 + 1))
	{
		stack_b->stack[i] = stack_a->stack[i + 1];
		i++;
	}

}
/* int	ft_push(int **stack_1, int **stack_2, int *size_1, int *size_2)
{
	int	*temp_1;
	int	*temp_2;
	int	i;

	if (!temp_1)
		return (0);
	temp_2 = (int *)malloc(sizeof(int) * (*size_2 - 1));
	if (!temp_2)
		return (ft_free(&temp_1), 0);
	temp_1[0] = *stack_2[0];
	i = *size_1 - 1 + 1;
	while (--i >= 0)
		temp_1[i + 1] = (*stack_1)[i];
	*size_1 = *size_1 + 1;
	i = *size_2 - 2 + 1;
	while (--i >= 0)
		temp_2[i] = (*stack_2)[i + 1];
	*size_2 = *size_2 - 1;
	return (free(*stack_1), *stack_1 = temp_1, free(*stack_2),
		*stack_2 = temp_2, 1);
} */
/* 
int	ft_push_a(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	if (!*stack_b || *size_b <= 0)
		return (0);
	if (!ft_push(stack_a, stack_b, size_a, size_b))
		return (ft_free(stack_a), ft_free(stack_b), 0);
	write(1, "pa\n", 3);
	return (1);
}

int	ft_push_b(int **stack_b, int **stack_a, int *size_b, int *size_a)
{
	if (!*stack_a || *size_a <= 0)
		return (0);
	if (!ft_push(stack_b, stack_a, size_b, size_a))
		return (ft_free(stack_a), ft_free(stack_b), 0);
	write(1, "pb\n", 3);
	return (1);
} */
