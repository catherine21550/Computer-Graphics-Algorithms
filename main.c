/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:56:47 by khuk              #+#    #+#             */
/*   Updated: 2024/07/01 21:56:51 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char *av[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	
	if (!create_stack_a(&stack_a, ac, av))
		return (1);
	printf("1:\n");
	if (ac == 2)
		stack_a.size = ft_counter(av[1], ' ');
	printf("2:\n");
	if (!ft_new_stack(&stack_b, stack_a.size))
		return (free(stack_a.stack), 1);
	printf("3:\n");
	if (stack_a.size > 4)
		sort_in_two(&stack_a, &stack_b);
	printf("4:\n");
	sort_small(&stack_a, &stack_b);
	printf("5:\n");
	printf("Stack A:\n");
	for(int i = 0; i < stack_a.size; i++)
			printf("%i\n", stack_a.stack[i]);
	printf("Stack B:\n");
	for(int i = 0; i < stack_b.size; i++)
		printf("%i\n", stack_b.stack[i]);
	printf("6:\n");
	if (!ft_sort_big(&stack_a, &stack_b))
		return (free(stack_a.stack), free(stack_b.stack), 1);
	printf("7:\n");
	while (!is_sorted(&stack_a))
	{
		if (find_min_index(&stack_a.stack, &stack_a.size)
			< (stack_a.size / 2))
			ft_rotate_a(&stack_a);
		else
			ft_rev_rotate_a(&stack_a);
	}
	printf("Stack A rotate:\n");
	for(int i = 0; i < stack_a.size; i++)
		printf("%i\n", stack_a.stack[i]);
	printf("Stack B rotate:\n");
	for(int i = 0; i < stack_b.size; i++)
		printf("%i\n", stack_b.stack[i]);
	return (free(stack_a.stack), free(stack_b.stack), 0);
}
