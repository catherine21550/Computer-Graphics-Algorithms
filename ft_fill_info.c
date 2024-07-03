/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:05:59 by khuk              #+#    #+#             */
/*   Updated: 2024/06/27 10:56:03 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ind_of_next(int *arr_a, int size_a, int nb)
{
	int	i;
	int	umin;
	int	res;

	i = 0;
	umin = arr_a[i] - nb;
	if (umin < 0)
	{
		while (umin < 0 && ++i < size_a)
			umin = arr_a[i] - nb;
	}
	res = i;
	while (i < size_a)
	{
		if (umin > (arr_a[i] - nb) && (arr_a[i] - nb) > 0)
		{
			umin = arr_a[i] - nb;
			res = i;
		}
		i++;
	}
	return (res);
}

void find_closest(t_stack *stack_a, t_stack *stack_b, t_node *inf)
{
	int			i;

	i = 0;
	while (i < stack_b->size)
	{
		inf[i].ind_clos = ind_of_next(stack_a->stack, stack_a->size, 
							stack_b->stack[i]);
		i++;
	}
}

void	fill_one(t_node *inf_arr, int *stack_a, int size_arr)
{
	int	i;

	i = 0;
	while (i < size_arr)
	{
		inf_arr[i].closest = stack_a[inf_arr[i].ind_clos];
		i++;
	}
	i = 0;
	while (i < size_arr)
	{
		if (i < (size_arr / 2))
			inf_arr[i].nb_ontop = i;
		else
			inf_arr[i].nb_ontop = size_arr - i;
		i++;
	}
}

void	fill_two(t_node *inf_arr, int *stack_b, int size_arr)
{
	int	i;

	i = 0;
	while (i < size_arr)
	{
		inf_arr[i].nb = stack_b[i];
		i++;
	}
	i = 0;
	while (i < size_arr)
	{
		if (inf_arr[i].ind_clos < (size_arr / 2))
			inf_arr[i].clos_ontop = inf_arr[i].ind_clos;
		else
			inf_arr[i].clos_ontop = size_arr - inf_arr[i].ind_clos;
		inf_arr[i].nb_index = i;
		i++;
	}
	i = 0;
	while (i < size_arr)
	{
		inf_arr[i].res_mvs = inf_arr[i].clos_ontop + inf_arr[i].nb_ontop;
		i++;
	}
}
