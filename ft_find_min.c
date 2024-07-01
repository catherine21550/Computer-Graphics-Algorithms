/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:04:12 by khuk              #+#    #+#             */
/*   Updated: 2024/07/01 20:04:16 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(int **arr, int *size)
{
	int	min;
	int	i;
	int	i_min;

	i = 0;
	min = (*arr)[i];
	i_min = 0;
	while (i <= (*size - 1))
	{
		if (min > (*arr)[i])
		{
			min = (*arr)[i];
			i_min = i;
		}
		i++;
	}
	return (i_min);
}

int	find_max_index(int **arr, int *size)
{
	int	max;
	int	i;
	int	i_max;

	i = 0;
	max = (*arr)[i];
	i_max = 0;
	while (i <= (*size - 1))
	{
		if (max < (*arr)[i])
		{
			max = (*arr)[i];
			i_max = i;
		}
		i++;
	}
	return (i_max);
}

int	find_min_mvs(t_node *inf_arr, int size)
{
	int	i;
	int	min;
	int	i_min;

	i = 0;
	min = inf_arr[0].res_mvs;
	i_min = 0;
	while (i < size)
	{
		if (min > inf_arr[i].res_mvs)
		{
			min = inf_arr[i].res_mvs;
			i_min = i;
		}
		i++;
	}
	return (i_min);
}
