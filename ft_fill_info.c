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
	int umin;
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

inf_node	*find_closest(int *arr_a, int *arr_b, int size_a, int size_b)
{
	int			i;
	inf_node	*calc;

	calc = (inf_node *)malloc(sizeof(inf_node) * size_b);
	if (!calc)
		return (NULL);
	i = 0;
	while (i < size_b)
	{
		calc[i].ind_clos = ind_of_next(arr_a, size_a, arr_b[i]);
		i++;
	}
	return (calc);
}

void	fill_one(inf_node *inf_arr, int *stack_a, int size_arr)
{
	int i;

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

void	fill_two(inf_node *inf_arr, int *stack_b, int size_arr)
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
