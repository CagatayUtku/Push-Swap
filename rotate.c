/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:57:07 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/06 11:01:57 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_llist **stack_a, t_llist **stack_b, int a, int b)
{
	t_llist	*last;

	if (a > 0)
	{
		last = (*stack_a);
		while (last -> next != NULL)
			last = last -> next;
		last -> next = *stack_a;
		while (a-- > 0)
			last = last -> next;
		*stack_a = last -> next;
		last -> next = NULL;
	}
	if (b > 0)
	{
		last = (*stack_b);
		while (last -> next != NULL)
			last = last -> next;
		last -> next = *stack_b;
		while (b-- > 0)
			last = last -> next;
		*stack_b = last -> next;
		last -> next = NULL;
	}
}
