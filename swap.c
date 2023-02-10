/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:58:01 by Cutku             #+#    #+#             */
/*   Updated: 2023/01/30 05:01:19 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_llist **stack_a, t_data *data)
{
	int	temp;

	if (data -> size_a > 1)
	{
		temp = (*stack_a)-> value;
		(*stack_a)-> value = (*stack_a)-> next -> value;
		(*stack_a)-> next -> value = temp;
	}
}

void	swap_b(t_llist **stack_b, t_data *data)
{
	int	temp;

	if (data -> size_b > 1)
	{
		temp = (*stack_b)-> value;
		(*stack_b)-> value = (*stack_b)-> next -> value;
		(*stack_b)-> next -> value = temp;
	}
}

void	swap_ab(t_llist **stack_a, t_llist **stack_b, t_data *data)
{
	int	temp;

	if ((data -> size_a > 1) && (data -> size_b > 1))
	{
		temp = (*stack_a)-> value;
		(*stack_a)-> value = (*stack_a)-> next -> value;
		(*stack_a)-> next -> value = temp;
		temp = (*stack_b)-> value;
		(*stack_b)-> value = (*stack_b)-> next -> value;
		(*stack_b)-> next -> value = temp;
	}
}
