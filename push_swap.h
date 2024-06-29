/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuk <khuk@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:14:10 by khuk              #+#    #+#             */
/*   Updated: 2024/06/28 16:33:34 by khuk             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# include <limits.h>

typedef struct	count_information
{
	int	nb;
	int nb_index;
	int	closest;
	int	ind_clos;
	int	clos_ontop;
	int nb_ontop;
	int	res_mvs;
}	inf_node;

int			ft_new_atoi(char *str);
int			ft_if_valid(char *str);
int			ft_check_limits(char *str);
int			ft_check_double(int ac, char *av[]);
int			*create_stack_a(int ac, char *av[]);
size_t		ft_counter(const char *str, char delc);
int			is_sorted(int **stack, int *size);
int			ft_is_sorted_before(int **stack, int begin, int end);
int			ft_is_sorted_after(int **stack, int begin, int end);
int			find_midvalue(int *arr, int	size);
int			find_min_index(int **arr, int *size);
int			find_max_index(int **arr, int *size);
int			find_min_mvs(inf_node *inf_arr, int size);
int			sort_in_two(int	**stack_a, int **stack_b, int *size_a, int *size_b);
//sort small
void		sort_five(int **arr, int *size);
void		sort_three(int **arr, int *size);
void		sort_four(int **arr_a, int **arr_b, int *size_a, int *size_b);
void		sort_small(int **arr_a, int **arr_b, int *size_a, int *size_b);
int		ft_sort_big(int *stack_a, int size_a, int *stack_b, int size_b);
//sort big
void	clos_ontop(int **stack_a, int *size_a, int index_clos);
void	nb_ontop(int **stack_b, int *size_b, int index_nb);
//create the array of struct with information
int			ind_of_next(int *arr, int size, int nb);
inf_node	*find_closest(int *arr_a, int *arr_b, int size_a, int size_b);
void		fill_one(inf_node *inf_arr, int *stack_a, int size_arr);
void		fill_two(inf_node *inf_arr, int *stack_b, int size_arr);
//rules
void		ft_swap(int *my_stack, int size);
void		ft_swap_a(int *my_stack, int size);
void		ft_swap_b(int *my_stack, int size);
void		ft_swap_ss(int *stack_a, int *stack_b, int size_a, int size_b);
int			ft_push(int **stack_1, int **stack_2, int *size_1, int *size_2);
int			ft_push_a(int **stack_a, int **stack_b, int *size_a, int *size_b);
int			ft_push_b(int **stack_b, int **stack_a, int *size_b, int *size_a);
int			ft_rotate_a(int **my_stack, int *size);
int			ft_rotate_b(int **my_stack, int *size);
int			ft_rotate_rr(int **my_stack_a, int **my_stack_b, int *size_a, int *size_b);
int			ft_rev_rotate_a(int **my_stack, int *size);
int			ft_rev_rotate_b(int **my_stack, int *size);
int			ft_rev_rotate_rrr(int **my_stack_a, int **my_stack_b, int *size_a, int *size_b);

#endif
