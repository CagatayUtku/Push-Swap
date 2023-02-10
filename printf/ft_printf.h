/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:08:36 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/06 12:05:25 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ptf_putchar(char c, int fd);
int		ptf_putstr_fd(char *s, int fd);
int		ft_printf(const char *format, ...);
int		printf_strlen(const char *str);
char	*printf_itoa(int n);
char	*ft_itoa_uint(unsigned long n, char *arr_base);

#endif