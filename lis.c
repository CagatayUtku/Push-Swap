/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:45:28 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/06 15:37:54 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_array(int *arr, int size)
{
	int	i;
	int	max;
	int	max_index;

	i = -1;
	max = 0;
	max_index = 0;
	while (++i < size)
	{
		if (max < arr[i])
		{
			max = arr[i];
			max_index = i;
		}
	}
	return (max_index);
}

int	*llist_to_array(t_llist *stack, t_data *data)
{
	int	i;
	int	*temp;

	temp = malloc(sizeof(int) * data -> size_a);
	if (!temp)
		return (NULL);
	i = 0;
	while (stack)
	{
		temp[i] = stack -> value;
		stack = stack -> next;
		i++;
	}
	return (temp);
}

int	*find_lis(t_data *data, int *temp)
{
	int	*lis;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * data -> size_a);
	if (!lis)
		return (NULL);
	i = -1;
	while (++i < data -> size_a)
		lis[i] = 1;
	i = 0;
	while (++i < data -> size_a)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (temp[j] < temp[i])
				lis[i] = max(lis[j] + 1, lis[i]);
			j--;
		}
	}
	return (lis);
}

int	*longest_increasing_subseq(t_llist *stack_a, t_data *data)
{
	int	i;
	int	max_index;
	int	*lis;
	int	*res;
	int	*temp;

	temp = llist_to_array(stack_a, data);
	lis = find_lis(data, temp);
	max_index = max_array(lis, data -> size_a) + 1;
	i = lis[max_index - 1];
	data -> size_lis = i;
	res = malloc(sizeof(int) * i);
	if (!res)
		return (NULL);
	while (--max_index >= 0)
		if (lis[max_index] == i)
			res[--i] = temp[max_index];
	return (free(lis), free(temp), res);
}
