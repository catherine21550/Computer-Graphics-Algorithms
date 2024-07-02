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
#include "printf/ft_printf.h"

int	main(int ac, char *av[])
{
	t_stack		my_stack;
	int *my_stack2 = NULL;
    int size_1 = ac - 1;
    int size_2 = 0;
	
	my_stack.stack = create_stack_a(ac, av);
	if (!my_stack.stack)
		return (1);
	if (ac == 2)
		size_1 = ft_counter(av[1], ' ');
	/* printf("My stack_a:\n");
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n");
	printf("My stack_b:\n");
	for (int i = 0; i < size_2; i++)
		ft_printf("%i\n", my_stack2[i]);
	ft_printf("---------------------\n"); */
	if (size_1 > 5)
		sort_in_two(&my_stack, &my_stack2, &size_1, &size_2);
	sort_small(&my_stack, &my_stack2, &size_1, &size_2);
	/* printf("My stack_a sorted:\n");
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n"); */
	if (!ft_sort_big(&my_stack, &size_1, &my_stack2, &size_2))
		return (ft_free(&my_stack), ft_free(&my_stack2), 1);
	while (!is_sorted(&my_stack, &size_1))
	{
		if (find_min_index(&my_stack, &size_1) < (size_1 / 2))
			ft_rotate_a(&my_stack, &size_1);
		else
			ft_rev_rotate_a(&my_stack, &size_1);
	}
	/* ft_printf("My stack_a result:\n");
	for (int i = 0; i < size_1; i++)
		ft_printf("%i\n", my_stack[i]);
	ft_printf("---------------------\n"); */
	free (my_stack);
	//free (my_stack2);
	return (0);
}
