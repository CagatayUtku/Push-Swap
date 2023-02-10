/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:21:29 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/09 18:26:19 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../gnl/get_next_line.h"

void	checker_controls(t_llist **check_a, t_llist **check_b);
void	exec_commands(t_llist **check_a, t_llist **check_b,
			t_data *check_data, char *command);
void	instruction_error(char *command);

#endif