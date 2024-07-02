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
	t_stack	my_stack;
	t_stack	my_stack2;
	
	my_stack.stack = create_stack_a(ac, av);
	if (!my_stack.stack)
		return (1);
	if (ac == 2)
		my_stack.size = ft_counter(av[1], ' ');
	if (!ft_new_stack(&my_stack2, my_stack.size));
		return (1);
	if (my_stack.size > 4)
		sort_in_two(&my_stack.stack, &my_stack2.stack, &my_stack.size, &my_stack2.size);
	sort_small(&my_stack, &my_stack2, &size_1, &size_2);
	if (!ft_sort_big(&my_stack, &size_1, &my_stack2, &size_2))
		return (ft_free(&my_stack), ft_free(&my_stack2), 1);
	while (!is_sorted(&my_stack, &size_1))
	{
		if (find_min_index(&my_stack, &size_1) < (size_1 / 2))
			ft_rotate_a(&my_stack, &size_1);
		else
			ft_rev_rotate_a(&my_stack, &size_1);
	}
	free (my_stack);
	return (0);
}
