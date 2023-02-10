/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:33:27 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/09 17:11:23 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_data(t_llist *stack_a, t_data *data)
{
	int	i;

	data -> min_a = INT_MAX;
	data -> max_a = INT_MIN;
	i = 0;
	while (stack_a)
	{
		if (stack_a -> value > data -> max_a)
			data -> max_a = stack_a -> value;
		if (stack_a -> value < data -> min_a)
		{
			data -> min_a = stack_a -> value;
			data -> min_index_a = i;
		}
		stack_a = stack_a -> next;
		i++;
	}
}

t_llist	*create_node(int val)
{
	t_llist	*new;

	new = malloc(sizeof(t_llist));
	if (!new)
		return (NULL);
	new->value = val;
	new ->next = NULL;
	return (new);
}

void	create_llist(t_llist **stack, char **argv)
{
	t_llist	*last;
	t_llist	*new;
	int		i;

	i = -1;
	if (*stack == NULL)
		(*stack) = create_node(ft_atoi(argv[++i]));
	if (*stack == NULL)
		return ;
	last = (*stack);
	while (last -> next != NULL)
		last = last->next;
	while (argv[++i] != NULL)
	{
		new = create_node(ft_atoi(argv[i]));
		if (new == NULL)
		{
			free_llist(stack);
			return ;
		}
		last -> next = new;
		last = new;
	}
}

int	insert_index_a(int target, t_llist *stack, t_data *data)
{
	int	i;

	if (target > stack->value && stack->next == NULL)
		return (1);
	if (target < data->min_a || target > data->max_a)
		return (data->min_index_a);
	i = 0;
	while (stack->next != NULL)
	{
		if (target > stack->value && target < stack->next->value)
			return (i + 1);
		i++;
		stack = stack->next;
	}
	return (0);
}

void	print_multi_rotate(t_data *data, t_cost *cost)
{
	if (cost->split[0] > 0 && cost->split[1] > 0)
	{
		cost->cop = min(cost->split[0], cost->split[1]);
		printf_num("rr", cost->cop, data);
		printf_num("ra", cost->split[0] - cost->cop, data);
		printf_num("rb", cost->split[1] - cost->cop, data);
	}
	else if (cost->split[0] < 0 && cost->split[1] < 0)
	{
		cost->cop = min(data->size_a + cost->split[0],
				data->size_b + cost->split[1]);
		printf_num("rrr", cost->cop, data);
		printf_num("rra", (data->size_a + cost->split[0]) - cost->cop, data);
		printf_num("rrb", (data->size_b + cost->split[1]) - cost->cop, data);
	}
	else if (cost->split[0] >= 0 && cost->split[1] <= 0)
	{
		printf_num("ra", cost->split[0], data);
		printf_num("rrb", cost->split[1], data);
	}
	else if (cost->split[0] <= 0 && cost->split[1] >= 0)
	{
		printf_num("rra", cost->split[0], data);
		printf_num("rb", cost->split[1], data);
	}
}
