/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:25:33 by khuk              #+#    #+#             */
/*   Updated: 2024/06/30 11:40:59 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clos_ontop(int **stack_a, int *size_a, int index_clos)
{
	int		i;

	i = 1;
	if (index_clos < (*size_a / 2))
		i = index_clos;
	else
		i = *size_a - index_clos;
	while (i != 0)
	{
		if (index_clos < (*size_a / 2))
			ft_rotate_a(stack_a, size_a);
		else
			ft_rev_rotate_a(stack_a, size_a);
		i--;
	}
}

void	nb_ontop(int **stack_b, int *size_b, int index_nb)
{
	int	i;

	i = 1;
	if (index_nb < (*size_b / 2))
		i = index_nb;
	else
		i = *size_b - index_nb;
	while (i != 0)
	{
		if (index_nb < (*size_b / 2))
			ft_rotate_b(stack_b, size_b);
		else
			ft_rev_rotate_b(stack_b, size_b);
		i--;
	}
}

int	ft_sort_big(int **stack_a, int *size_a, int **stack_b, int *size_b)
{
	t_node	*inf;
	int			size_arr;
	int			i;

	inf = NULL;
	size_arr = 0;
	i = *size_b;
	while (i != 0)
	{
		size_arr = *size_b;
		inf = find_closest(*stack_a, *stack_b, *size_a, *size_b);
		if (!inf)
			return (0);
		fill_one(inf, *stack_a, size_arr);
		fill_two(inf, *stack_b, size_arr);
		clos_ontop(stack_a, size_a, inf[find_min_mvs(inf, size_arr)].ind_clos);
		nb_ontop(stack_b, size_b, find_min_mvs(inf, size_arr));
		if (!ft_push_a(stack_a, stack_b, size_a, size_b))
			return (free(inf), ft_free(stack_a), ft_free(stack_b), 0);
		free(inf);
		i--;
	}
	return (1);
}
