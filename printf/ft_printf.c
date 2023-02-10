/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:49:20 by Cutku             #+#    #+#             */
/*   Updated: 2023/02/06 12:05:22 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_utils(va_list ap, char a, int res, char *str)
{
	if (a == 'p')
	{
		str = ft_itoa_uint(va_arg(ap, unsigned long), "0123456789abcdef");
		write (1, "0x", 2);
		res += ptf_putstr_fd(str, 1) + 2;
	}
	else if (a == 'u')
	{
		str = ft_itoa_uint(va_arg(ap, unsigned int), "0123456789");
		res += ptf_putstr_fd(str, 1);
	}
	else if (a == 'x')
	{
		str = ft_itoa_uint(va_arg(ap, unsigned int), "0123456789abcdef");
		res += ptf_putstr_fd(str, 1);
	}
	else if (a == 'X')
	{
		str = ft_itoa_uint(va_arg(ap, unsigned int), "0123456789ABCDEF");
		res += ptf_putstr_fd(str, 1);
	}
	free(str);
	return (res);
}

int	ft_printf_utils(va_list ap, char a)
{
	char	*str;
	int		res;

	res = 0;
	str = NULL;
	if (a == 'c')
		res += ptf_putchar((char)va_arg(ap, int), 1);
	else if (a == 's')
		res += ptf_putstr_fd(va_arg(ap, char *), 1);
	else if (a == 'd' || a == 'i')
	{
		str = printf_itoa(va_arg(ap, int));
		res += ptf_putstr_fd(str, 1);
		free(str);
	}
	else if (a == '%')
		res += ptf_putchar('%', 1);
	else if (a == 'x' || a == 'X' || a == 'u' || a == 'p')
		res += ft_unsigned_utils(ap, a, res, str);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	res = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			res += ft_printf_utils(ap, format[i++]);
		}
		else
			res += ptf_putchar(format[i++], 1);
	}
	va_end(ap);
	return (res);
}

// int main (void)
// {
// 	int x, y;
// 	x = ft_printf("%s", NULL);
// 	y = ft_printf("%s", NULL);
// 	ft_printf("%d\n%d\n",x, y);
// 	return (0);
// }