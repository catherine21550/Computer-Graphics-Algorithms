/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:25:33 by khuk              #+#    #+#             */
/*   Updated: 2024/06/27 16:34:11 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clos_ontop(int **stack_a, int *size_a, int index_clos)
{
	int	i;
	
	i = 1;
	while (i != 0)
	{
		if (index_clos < (*size_a / 2))
		{
			i = index_clos;
			ft_rotate_a(stack_a, size_a);
		}
		else
		{
			i = size_a - index_clos;
			ft_rev_rotate_a(stack_a, size_a);
		}
		i--;
	}
}

void	nb_ontop(int **stack_b, int *size_b, int index_nb)
{
	int	i;
	
	i = 1;
	while (i != 0)
	{
		if (index_nb < (*size_b / 2))
		{
			i = index_nb;
			ft_rotate_b(stack_b, size_b);
		}
		else
		{
			i = size_b - index_nb;
			ft_rev_rotate_b(stack_b, size_b);
		}
		i--;
	}
}

int	ft_sort_big(inf_node *inf, int arr_size, int *stack_a, int size_a, int *stack_b, int size_b)
{
	
}