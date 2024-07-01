/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:53:44 by khuk              #+#    #+#             */
/*   Updated: 2024/06/17 09:20:20 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rotate(int **my_stack, int *size)
{
	int	temp;
	int	i;

	temp = (*my_stack)[*size - 1];
	i = *size - 1;
	while (i > 0)
	{
		(*my_stack)[i] = (*my_stack)[i - 1];
		i--;
	}
	(*my_stack)[0] = temp;
}

int	ft_rev_rotate_a(int **my_stack, int *size)
{
	if (*size <= 0 || *my_stack == NULL)
		return (0);
	ft_rev_rotate(my_stack, size);
	write(1, "rra\n", 4);
	return (1);
}

int	ft_rev_rotate_b(int **my_stack, int *size)
{
	if (*size <= 0 || *my_stack == NULL)
		return (0);
	ft_rev_rotate(my_stack, size);
	write(1, "rrb\n", 4);
	return (1);
}

int	ft_rev_rotate_rrr(int **my_stack_a, int **my_stack_b,
						int *size_a, int *size_b)
{
	if (*size_a <= 0 || !(*my_stack_a) || *size_b <= 0 || !(*my_stack_a))
		return (0);
	ft_rev_rotate(my_stack_a, size_a);
	ft_rev_rotate(my_stack_b, size_b);
	write(1, "rrr\n", 4);
	return (1);
}
