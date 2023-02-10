/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:51:59 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/03 15:53:16 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_dubleptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_llist(t_llist **stack)
{
	t_llist	*del;

	while (*stack != NULL)
	{
		del = *stack;
		*stack = (*stack)-> next;
		free(del);
	}
}
