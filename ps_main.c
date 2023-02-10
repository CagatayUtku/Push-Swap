/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:04:47 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/06 17:09:36 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_llist	*stack_a;
	t_llist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (parse_arguments(argc, argv, &stack_a))
		{
			push_swap(&stack_a, &stack_b);
			free_llist(&stack_a);
		}
		else
			return (-1);
	}
	return (0);
}
