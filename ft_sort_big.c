/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:25:33 by khuk              #+#    #+#             */
/*   Updated: 2024/07/11 00:05:11 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clos_ontop(t_stack *stack_a, int index_clos)
{
	int	i;

	i = 1;
	if (index_clos < (stack_a->size / 2))
		i = index_clos;
	else
		i = stack_a->size - index_clos;
	while (i != 0)
	{
		if (index_clos < (stack_a->size / 2))
			ft_rotate_a(stack_a);
		else
			ft_rev_rotate_a(stack_a);
		i--;
	}
}

void	nb_ontop(t_stack *stack_b, int index_nb)
{
	int	i;

	i = 1;
	if (index_nb < (stack_b->size / 2))
		i = index_nb;
	else
		i = stack_b->size - index_nb;
	while (i != 0)
	{
		if (index_nb < (stack_b->size / 2))
			ft_rotate_b(stack_b);
		else
			ft_rev_rotate_b(stack_b);
		i--;
	}
}

int	ft_sort_big(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*inf;
	int		size_arr;
	int		i;

	inf = NULL;
	size_arr = 0;
	i = stack_b->size;
	inf = (t_node *)malloc(sizeof(t_node) * stack_b->size);
	if (!inf)
		return (0);
	while (i != 0)
	{
		size_arr = stack_b->size;
		find_closest(stack_a, stack_b, inf);
		fill_one(inf, stack_a->stack, size_arr);
		fill_two(inf, stack_b->stack, size_arr);
		fill_three(inf, stack_a, stack_b);
		rotate_ontop(stack_a, stack_b, &inf[find_min_mvs(inf, size_arr)]);
		ft_push_a(stack_a, stack_b);
		i--;
	}
	return (free(inf), 1);
}
