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
	i = stack_a->size - 2;
	while (i >= 0)
	{
		stack_a->stack[i + 1] = stack_a->stack[i];
		i--;
	}
	stack_a->stack[0] = stack_b->stack[0];
	stack_b->size = stack_b->size - 1;
	i = 0;
	while (i < (stack_b->size))
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	stack_b->size = stack_b->size + 1;
	i = stack_b->size - 2;
	while (i >= 0)
	{
		stack_b->stack[i + 1] = stack_b->stack[i];
		i--;
	}
	stack_b->stack[0] = stack_a->stack[0];
	stack_a->size = stack_a->size - 1;
	i = 0;
	while (i < (stack_a->size))
	{
		stack_a->stack[i] = stack_a->stack[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
}
/* 
int	ft_new_stack(t_stack *new_stack, int size)
{
	if (size == 0)
		return (0);
	else
	{
		new_stack->size = size;
		new_stack->stack = (int *)malloc(sizeof(int) * size);
		if (!new_stack->stack)
			return (0);
	}
	return (1);
}

#include <stdio.h>

int	main()
{
	t_stack	A;
	t_stack	B;


	ft_new_stack(&A, 4);
	ft_new_stack(&B, 4);
	for(int i = 0, j = 1; i < A.size; i++, j++)
		A.stack[i] = j;
	for(int i = 0, j = 5; i < B.size; i++, j++)
		B.stack[i] = j;
	printf("Stack A:\n");
	for(int i = 0; i < A.size; i++)
			printf("%i\n", A.stack[i]);
	printf("Stack B:\n");
	for(int i = 0; i < B.size; i++)
		printf("%i\n", B.stack[i]);
	ft_push_b(&A, &B);
	printf("Stack A:\n");
	for(int i = 0; i < A.size; i++)
		printf("%i\n", A.stack[i]);
	printf("Stack B:\n");
	for(int i = 0; i < B.size; i++)
		printf("%i\n", B.stack[i]);
	ft_rev_rotate_a(&A);
	ft_rev_rotate_b(&B);
	printf("Stack A rotate:\n");
	for(int i = 0; i < A.size; i++)
		printf("%i\n", A.stack[i]);
	printf("Stack B rotate:\n");
	for(int i = 0; i < B.size; i++)
		printf("%i\n", B.stack[i]);
	free(A.stack);
	free(B.stack);
	return (0);
} */