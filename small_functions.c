/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:04:40 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/06 10:50:51 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_linklist(t_llist *stack)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		counter++;
		stack = stack->next;
	}
	return (counter);
}

int	ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}

int	median_unsortedllist(t_llist *stack, t_data *data)
{
	t_llist	*ptr;
	t_llist	*head;
	int		counter;

	head = stack;
	while (head)
	{
		ptr = stack;
		counter = 0;
		while (ptr)
		{
			if (head ->value > ptr -> value)
				counter++;
			ptr = ptr->next;
		}
		if (counter == (data->size_a / 2))
			return (head->value);
		head = head -> next;
	}
	return (-1);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
