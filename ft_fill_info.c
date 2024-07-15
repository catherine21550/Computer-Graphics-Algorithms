/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:05:59 by khuk              #+#    #+#             */
/*   Updated: 2024/07/11 00:04:47 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ind_of_next(int *arr_a, int size_a, int nb)
{
	int			i;
	long long	umin;
	long long	tmp;
	int			res;

	i = 0;
	res = 0;
	umin = (long long int)arr_a[i] - (long long int)nb;
	if (umin < 0)
	{
		while (umin < 0 && ++i < size_a)
			umin = (long long int)(arr_a[i]) - (long long int)(nb);
	}
	res = i;
	while (i < size_a)
	{
		tmp = (long long int)(arr_a[i]) - (long long int)(nb);
		if (umin > tmp && tmp > 0)
		{
			umin = tmp;
			res = i;
		}
		i++;
	}
	return (res);
}

void	find_closest(t_stack *stack_a, t_stack *stack_b, t_node *inf)
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
}

void	fill_three(t_node *n, t_stack *A, t_stack *B)
{
	int	i;

	i = 0;
	while (i < B->size)
	{
		if (n[i].ind_clos < (A->size / 2) && n[i].nb_index < (B->size / 2))
		{
			if (n[i].ind_clos < n[i].nb_index)
				n[i].res_mvs = n[i].nb_index;
			else
				n[i].res_mvs = n[i].ind_clos;
		}
		else if (n->ind_clos >= (A->size / 2) && n->nb_index >= (B->size / 2))
		{
			if ((A->size - n->ind_clos) < (B->size - n->nb_index))
				n[i].res_mvs = (B->size - n->nb_index);
			else
				n[i].res_mvs = (A->size - n->ind_clos);
		}
		else
			n[i].res_mvs = n[i].clos_ontop + n[i].nb_ontop;
		i++;
	}
}
