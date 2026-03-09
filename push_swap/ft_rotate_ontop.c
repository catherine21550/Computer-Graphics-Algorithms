/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:36:21 by khuk              #+#    #+#             */
/*   Updated: 2024/07/04 17:36:26 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	rotate_two(t_stack *A, t_stack *B, t_node *inf)
{
	int	i[2];

	i[0] = 1;
	i[1] = 1;
	if (inf->ind_clos < inf->nb_index)
	{
		i[0] = inf->ind_clos + 1;
		i[1] = inf->nb_index - inf->ind_clos + 1;
		while (--i[0] != 0)
			ft_rotate_rr(A, B);
		while (--i[1] != 0)
			ft_rotate_b(B);
	}
	else
	{
		i[0] = inf->nb_index + 1;
		i[1] = inf->ind_clos - inf->nb_index +1;
		while (--i[0] != 0)
			ft_rotate_rr(A, B);
		while (--i[1] != 0)
			ft_rotate_a(A);
	}
}

void	rev_rotate_two(t_stack *A, t_stack *B, t_node *n)
{
	int	i[2];

	i[0] = 1;
	i[1] = 1;
	if ((A->size - n->ind_clos) < (B->size - n->nb_index))
	{
		i[0] = (A->size - n->ind_clos) + 1;
		i[1] = (B->size - n->nb_index) - (A->size - n->ind_clos) + 1;
		while (--i[0] != 0)
			ft_rev_rotate_rrr(A, B);
		while (--i[1] != 0)
			ft_rev_rotate_b(B);
	}
	else
	{
		i[0] = (B->size - n->nb_index) + 1;
		i[1] = (A->size - n->ind_clos) - (B->size - n->nb_index) + 1;
		while (--i[0] != 0)
			ft_rev_rotate_rrr(A, B);
		while (--i[1] != 0)
			ft_rev_rotate_a(A);
	}
}

void	rotate_ontop(t_stack *A, t_stack *B, t_node *n)
{
	if (n->ind_clos < (A->size / 2) && n->nb_index < (B->size / 2))
		rotate_two(A, B, n);
	else if (n->ind_clos >= (A->size / 2) && n->nb_index >= (B->size / 2))
		rev_rotate_two(A, B, n);
	else
	{
		clos_ontop(A, n->ind_clos);
		nb_ontop(B, n->nb_index);
	}
}
/* 
int	ft_new_stack(t_stack *new_stack, int size)
{
	if (size == 0)
		return (0);
	else
	{
		new_stack->size = size;
		new_stack->stack = (int *)malloc(sizeof(int) * size);
		if (!new_stack->stack)
			return (0);
	}
	return (1);
}

#include <stdio.h>

int	main()
{
	t_stack	A;
	t_stack	B;
	t_node	inf;

	inf.ind_clos = 6;
	inf.nb_index = 5;
	ft_new_stack(&A, 8);
	ft_new_stack(&B, 8);
	for(int i = 0, j = 1; i < A.size; i++, j++)
		A.stack[i] = j;
	for(int i = 0, j = 9; i < B.size; i++, j++)
		B.stack[i] = j;
	printf("Stack A:\n");
	for(int i = 0; i < A.size; i++)
			printf("%i\n", A.stack[i]);
	printf("Stack B:\n");
	for(int i = 0; i < B.size; i++)
		printf("%i\n", B.stack[i]);
	rotate_ontop(&A, &B, &inf);
	printf("Stack A rotate:\n");
	for(int i = 0; i < A.size; i++)
		printf("%i\n", A.stack[i]);
	printf("Stack B rotate:\n");
	for(int i = 0; i < B.size; i++)
		printf("%i\n", B.stack[i]);
	free(A.stack);
	free(B.stack);
	return (0);
} */
