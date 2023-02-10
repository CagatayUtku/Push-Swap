/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:58:48 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/09 18:41:01 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_all_num(char *s1)
{
	int	i;

	i = 0;
	if (s1[0] == '-' || s1[0] == '+')
		i++;
	while (s1[i] != '\0')
	{
		if (!(s1[i] >= '0' && s1[i] <= '9'))
			return (0);
		i++;
	}
	if (i == 1 && (s1[0] == '-' || s1[0] == '+'))
		return (0);
	return (1);
}

int	is_duplicate(char **s1, t_llist *stack_a)
{
	int	i;
	int	num1;

	num1 = ft_atoi(s1[0]);
	while (stack_a)
	{
		if (num1 == stack_a -> value)
			return (0);
		stack_a = stack_a->next;
	}
	i = 1;
	while (s1[i] != NULL)
	{
		if (num1 == ft_atoi(s1[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_integer(char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
		if (result > INT_MAX && sign == 1)
			return (0);
		if (result > ((long)INT_MAX + 1) && sign == -1)
			return (0);
	}
	return (1);
}

int	error_control(char **argv, t_llist *stack_a)
{
	int	i;
	int	j;

	j = 0;
	while (argv[j] != NULL)
		j++;
	i = 0;
	while (i < j)
	{
		if (!is_all_num(argv[i]))
			return (0);
		if (!is_integer(argv[i]))
			return (0);
		if (!is_duplicate(argv + i, stack_a))
			return (0);
		i++;
	}
	return (i);
}
