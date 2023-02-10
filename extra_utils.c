/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:42:55 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/09 17:44:11 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_num(char *str, int num, t_data *data)
{
	int	i;

	if (num < 0)
	{
		if (str[2] == 'a')
			num = data->size_a + num;
		else
			num = data->size_b + num;
	}
	i = -1;
	while (++i < num)
		ft_printf("%s\n", str);
}

int	parse_arguments(int argc, char **argv, t_llist **stack_a)
{
	int		i;
	char	**ptr;

	i = 0;
	while (++i < argc)
	{
		ptr = ft_split(argv[i], ' ');
		if (error_control(ptr, *stack_a))
			create_llist(stack_a, ptr);
		else
		{
			if (stack_a)
				free_llist(stack_a);
			free_dubleptr(ptr);
			write(2, "Error\n", 6);
			return (0);
		}
		free_dubleptr(ptr);
	}
	return (1);
}

void	last_sort(t_llist **stack_a, t_llist **stack_b, t_data *data)
{
	find_data((*stack_a), data);
	if (data->min_index_a < (data->size_a / 2.0))
	{
		rotate(stack_a, stack_b, data->min_index_a, 0);
		printf_num("ra", data->min_index_a, data);
	}
	else
	{
		rotate(stack_a, stack_b, data->min_index_a, 0);
		printf_num("rra", -data->min_index_a, data);
	}
}

int	is_sorted(t_llist *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
