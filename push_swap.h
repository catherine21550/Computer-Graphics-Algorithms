/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:14:10 by khuk              #+#    #+#             */
/*   Updated: 2024/07/03 23:08:06 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# include <limits.h>

typedef struct count_information
{
	int	nb;
	int	nb_index;
	int	closest;
	int	ind_clos;
	int	clos_ontop;
	int	nb_ontop;
	int	res_mvs;
}	t_node;

typedef struct stack_struct
{
	int	*stack;
	int	size;
}	t_stack;

int		ft_new_atoi(char *str);
int		ft_if_valid(char *str);
int		ft_check_limits(char *str);
int		ft_check_double(int ac, char *av[]);
int		check_ifspace(char *str);
//create stack A
int		create_stack_a(t_stack *my_stack, int ac, char *av[]);
int		ft_new_stack(t_stack *new_stack, int size);
int		ft_fillarray(char **str_arr, t_stack *arr, int ac);
void	ft_free(int *content);
char	**process_argv(char *str, int *n);
size_t	ft_counter(const char *str, char delc);
int		is_sorted(t_stack *my_stack);
int		find_midvalue(int *arr, int size);
int		find_min_index(int **arr, int *size);
int		find_max_index(int **arr, int *size);
int		find_min_mvs(t_node *inf_arr, int size);
void	sort_in_two(t_stack	*stack_a, t_stack *stack_b);
void	final_rotate(t_stack *stack_a);
//sort small
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
//sort big
void	rotate_two(t_stack *A, t_stack *B, t_node *inf);
void	rev_rotate_two(t_stack *A, t_stack *B, t_node *n);
void	clos_ontop(t_stack *stack_a, int index_clos);
void	nb_ontop(t_stack *stack_b, int index_nb);
void	rotate_ontop(t_stack *A, t_stack *B, t_node *n);
int		ft_sort_big(t_stack *stack_a, t_stack *stack_b);
//create the array of struct with information
int		ind_of_next(int *arr, int size, int nb);
void	find_closest(t_stack *stack_a, t_stack *stack_b, t_node *inf);
void	fill_one(t_node *inf_arr, int *stack_a, int size_arr);
void	fill_two(t_node *inf_arr, int *stack_b, int size_arr);
void	fill_three(t_node *n, t_stack *A, t_stack *B);
//rules
void	ft_swap(t_stack *my_stack);
void	ft_swap_a(t_stack *stack_a);
void	ft_swap_b(t_stack *stack_b);
void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_push_a(t_stack *stack_a, t_stack *stack_b);
void	ft_push_b(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate_a(t_stack *stack_a);
void	ft_rotate_b(t_stack *stack_b);
void	ft_rotate_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rev_rotate_a(t_stack *stack_a);
void	ft_rev_rotate_b(t_stack *stack_b);
void	ft_rev_rotate_rrr(t_stack *stack_a, t_stack *stack_b);

#endif