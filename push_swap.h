/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:14:10 by khuk              #+#    #+#             */
/*   Updated: 2024/06/20 15:48:24 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

int		ft_new_atoi(char *str);
int		ft_if_valid(char *str);
int		*create_stack_a(int ac, char *av[]);
int	    ft_sort1(int **stack, int *size);

void	ft_swap(int *my_stack, int size);
void	ft_swap_a(int *my_stack, int size);
void	ft_swap_b(int *my_stack, int size);
void	ft_swap_ss(int *stack_a, int *stack_b, int size_a, int size_b);
int		ft_push(int **stack_1, int **stack_2, int *size_1, int *size_2);
int		ft_push_a(int **stack_a, int **stack_b, int *size_a, int *size_b);
int		ft_push_b(int **stack_b, int **stack_a, int *size_b, int *size_a);
int		ft_rotate_a(int **my_stack, int *size);
int		ft_rotate_b(int **my_stack, int *size);
int		ft_rotate_rr(int **my_stack_a, int **my_stack_b, int *size_a, int *size_b);
int		ft_rev_rotate_a(int **my_stack, int *size);
int		ft_rev_rotate_b(int **my_stack, int *size);
int		ft_rev_rotate_rrr(int **my_stack_a, int **my_stack_b, int *size_a, int *size_b);
size_t  ft_counter(const char *str, char delc);
int		is_sorted(int **stack, int *size);

#endif
