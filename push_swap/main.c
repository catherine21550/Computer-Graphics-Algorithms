/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:56:47 by khuk              #+#    #+#             */
/*   Updated: 2024/07/11 00:05:48 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.stack = NULL;
	stack_b.stack = NULL;
	if (ac == 1)
		return (0);
	if (!create_stack_a(&stack_a, ac, av))
		return (ft_free(stack_a.stack), 1);
	if (ac == 2)
		stack_a.size = ft_counter(av[1], ' ');
	if (is_sorted(&stack_a))
		return (ft_free(stack_a.stack), 0);
	if (!ft_new_stack(&stack_b, stack_a.size))
		return (ft_free(stack_a.stack), 1);
	stack_b.size = 0;
	if (stack_a.size > 4)
		sort_in_two(&stack_a, &stack_b);
	sort_small(&stack_a, &stack_b);
	if (!ft_sort_big(&stack_a, &stack_b))
		return (ft_free(stack_a.stack), ft_free(stack_b.stack), 1);
	final_rotate(&stack_a);
	return (free(stack_a.stack), free(stack_b.stack), 0);
}
