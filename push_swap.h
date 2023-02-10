/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:47:43 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/09 18:26:01 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_llist
{
	int				value;
	struct s_llist	*next;
}t_llist;

typedef struct s_cost
{
	int		rot_a;
	int		rot_b;
	int		tot;
	int		cop;
	int		split[2];
}t_cost;

typedef struct s_data
{
	int		size_a;
	int		size_b;
	int		size_lis;
	int		max_a;
	int		min_a;
	int		median;
	int		min_index_a;
}t_data;

//Stack Operations
void	sep_small_stacks(t_llist **stack_a, t_llist **stack_b, t_data *data);
void	sep_big_stacks(t_llist **stack_a, t_llist **stack_b, t_data *data);
void	find_shortest_step(t_llist *stack_a, t_llist *stack_b, t_data *data,
			t_cost *cost);
void	print_multi_rotate(t_data *data, t_cost *cost);
int		insert_index_a(int target, t_llist *stack, t_data *data);
int		*longest_increasing_subseq(t_llist *stack_a, t_data *data);
void	last_sort(t_llist **stack_a, t_llist **stack_b, t_data *data);
void	push_swap(t_llist **stack_a, t_llist **stack_b);
int		is_sorted(t_llist *stack_a);
//Initializations
int		parse_arguments(int argc, char **argv, t_llist **stack_a);
void	create_llist(t_llist **stack, char **argv);
void	find_data(t_llist *stack_a, t_data *data);
//Small Functions
int		min(int a, int b);
int		max(int a, int b);
int		ft_abs(int a);
int		median_unsortedllist(t_llist *stack, t_data *data);
int		max_array(int *arr, int size);
int		len_linklist(t_llist *stack);
void	free_dubleptr(char **ptr);
void	free_llist(t_llist **stack);
void	printf_num(char *str, int num, t_data *data);
//Error Controls
int		error_control(char **argv, t_llist *stack_a);
int		is_integer(char *str);
int		is_duplicate(char **s1, t_llist *stack_a);
int		is_all_num(char *s1);
//Push_swap Operations
void	push_a(t_llist **stack_a, t_llist **stack_b, t_data *data);
void	push_b(t_llist **stack_a, t_llist **stack_b, t_data *data);
void	swap_a(t_llist **stack_a, t_data *data);
void	swap_b(t_llist **stack_b, t_data *data);
void	swap_ab(t_llist **stack_a, t_llist **stack_b, t_data *data);
void	rotate(t_llist **stack_a, t_llist **stack_b, int a, int b);

#endif