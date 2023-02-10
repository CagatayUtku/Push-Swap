/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:18:46 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/09 17:35:18 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	instruction_error(char *command)
{
	free(command);
	write(2, "Error\n", 6);
	exit(-1);
}

void	exec_commands(t_llist **check_a, t_llist **check_b,
			t_data *check_data, char *command)
{
	if (!ft_strncmp(command, "pa\n", 3))
		push_a(check_a, check_b, check_data);
	else if (!ft_strncmp(command, "pb\n", 3))
		push_b(check_a, check_b, check_data);
	else if (!ft_strncmp(command, "sa\n", 3))
		swap_a(check_a, check_data);
	else if (!ft_strncmp(command, "sb\n", 3))
		swap_b(check_b, check_data);
	else if (!ft_strncmp(command, "ss\n", 3))
		swap_ab(check_a, check_b, check_data);
	else if (!ft_strncmp(command, "ra\n", 3))
		rotate(check_a, check_b, 1, 0);
	else if (!ft_strncmp(command, "rb\n", 3))
		rotate(check_a, check_b, 0, 1);
	else if (!ft_strncmp(command, "rr\n", 3))
		rotate(check_a, check_b, 1, 1);
	else if (!ft_strncmp(command, "rra\n", 4))
		rotate(check_a, check_b, check_data->size_a - 1, 0);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rotate(check_a, check_b, 0, check_data->size_b - 1);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rotate(check_a, check_b, check_data->size_a - 1,
			check_data->size_b - 1);
	else
		instruction_error(command);
}

void	checker_controls(t_llist **check_a, t_llist **check_b)
{
	char	*command;
	t_data	check_data;

	check_data.size_a = len_linklist(*check_a);
	check_data.size_b = 0;
	command = get_next_line(0);
	while (command != NULL)
	{
		exec_commands(check_a, check_b, &check_data, command);
		free(command);
		command = get_next_line(0);
	}
	if (is_sorted(*check_a) && !len_linklist(*check_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_llist(check_a);
}

int	main(int argc, char **argv)
{
	t_llist	*check_a;
	t_llist	*check_b;

	check_a = NULL;
	check_b = NULL;
	if (argc > 1)
	{
		if (parse_arguments(argc, argv, &check_a))
			checker_controls(&check_a, &check_b);
		else
			return (-1);
	}
	return (0);
}
