/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:26:52 by khuk              #+#    #+#             */
/*   Updated: 2024/06/25 12:16:43 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_closest(int *arr_a, int *arr_b, int size_a, int size_b)
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

int	ind_of_next(int *arr, int size, int nb)
{
	int	res;
	int	i;

	res = 0;
	i = 1;
	while (i < size)
	{
		if ((arr[i] - nb) < (arr[i - 1] - nb))
			res = i;
		i++;
	}
	return (res);
}