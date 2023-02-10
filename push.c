/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:43:42 by Cutku             #+#    #+#             */
/*   Updated: 2023/01/30 05:00:23 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_llist **stack_a, t_llist **stack_b, t_data *data)
{
	t_llist	*temp;

	if (data -> size_a > 0)
	{
		temp = (*stack_a);
		(*stack_a) = (*stack_a)-> next;
		temp -> next = (*stack_b);
		(*stack_b) = temp;
		data -> size_a--;
		data -> size_b++;
	}
}

void	push_a(t_llist **stack_a, t_llist **stack_b, t_data *data)
{
	t_llist	*temp;

	if (data -> size_b > 0)
	{
		temp = (*stack_b);
		(*stack_b) = (*stack_b)-> next;
		temp -> next = (*stack_a);
		(*stack_a) = temp;
		data -> size_b--;
		data -> size_a++;
	}
}
