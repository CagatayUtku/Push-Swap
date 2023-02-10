/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:58:13 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/09 17:11:17 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_cost(t_cost *cost, t_data *data)
{
	if (cost->tot > max(cost->rot_a, cost->rot_b))
	{
		cost->tot = max(cost->rot_a, cost->rot_b);
		cost->split[0] = cost->rot_a;
		cost->split[1] = cost->rot_b;
	}
	if (cost->tot > max(data->size_a - cost->rot_a, data->size_b - cost->rot_b))
	{
		cost->tot = max(data->size_a - cost->rot_a, data->size_b - cost->rot_b);
		cost->split[0] = -cost->rot_a;
		cost->split[1] = -cost->rot_b;
	}
	if (cost->tot > (cost->rot_a + (data->size_b - cost->rot_b)))
	{
		cost->tot = cost->rot_a + (data->size_b - cost->rot_b);
		cost->split[0] = cost->rot_a;
		cost->split[1] = -cost->rot_b;
	}
	if (cost->tot > (data->size_a - cost->rot_a) + cost->rot_b)
	{
		cost->tot = (data->size_a - cost->rot_a) + cost->rot_b;
		cost->split[0] = -cost->rot_a;
		cost->split[1] = cost->rot_b;
	}
}

void	find_shortest_step(t_llist *stack_a, t_llist *stack_b, t_data *data,
		t_cost *cost)
{
	int	i;

	i = -1;
	cost->tot = INT_MAX;
	while (++i < data->size_b)
	{
		cost->rot_a = insert_index_a(stack_b->value, stack_a, data);
		cost->rot_b = i;
		min_cost(cost, data);
		stack_b = stack_b->next;
	}
}

void	sep_small_stacks(t_llist **stack_a, t_llist **stack_b, t_data *data)
{
	while (data->size_a > 3 && !is_sorted(*stack_a))
	{
		push_b(stack_a, stack_b, data);
		ft_printf("pb\n");
	}
	last_sort(stack_a, stack_b, data);
	if (!is_sorted(*stack_a))
	{
		swap_a(stack_a, data);
		ft_printf("sa\n");
		rotate(stack_a, stack_b, 1, 0);
		ft_printf("ra\n");
	}
}

void	sep_big_stacks(t_llist **stack_a, t_llist **stack_b, t_data *data)
{
	int	*lis;

	lis = longest_increasing_subseq((*stack_a), data);
	while (data->size_a > data->size_lis)
	{
		if ((*stack_a)->value != *lis && (*stack_a)->value > data->median)
		{
			push_b(stack_a, stack_b, data);
			rotate(stack_a, stack_b, 0, 1);
			ft_printf("pb\n");
			ft_printf("rb\n");
		}
		else if ((*stack_a)->value != *lis && (*stack_a)->value <= data->median)
		{
			push_b(stack_a, stack_b, data);
			ft_printf("pb\n");
		}
		else
		{
			rotate(stack_a, stack_b, 1, 0);
			ft_printf("ra\n");
			lis++;
		}
	}
	free(longest_increasing_subseq((*stack_a), data));
}

void	push_swap(t_llist **stack_a, t_llist **stack_b)
{
	t_cost	cost;
	t_data	data;

	data.size_a = len_linklist(*stack_a);
	data.size_b = 0;
	data.median = median_unsortedllist(*stack_a, &data);
	if (data.size_a <= 10)
		sep_small_stacks(stack_a, stack_b, &data);
	else
		sep_big_stacks(stack_a, stack_b, &data);
	while (data.size_b > 0)
	{
		find_data((*stack_a), &data);
		find_shortest_step((*stack_a), (*stack_b), &data, &cost);
		rotate(stack_a, stack_b, ft_abs(cost.split[0]), ft_abs(cost.split[1]));
		print_multi_rotate(&data, &cost);
		push_a(stack_a, stack_b, &data);
		ft_printf("pa\n");
	}
	last_sort(stack_a, stack_b, &data);
}
