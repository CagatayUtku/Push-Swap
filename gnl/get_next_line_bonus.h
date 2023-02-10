/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:30:50 by Cutku             #+#    #+#             */
/*   Updated: 2023/01/20 21:41:41 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define MAX_FILES 1024

char	*get_next_line(int fd);
int		gnl_strlen(char *str);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *s, int c);
char	*gnl_substr(char *s, unsigned int start, size_t len);

#endif