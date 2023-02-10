/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:07:34 by Cutku             #+#    #+#             */
/*   Updated: 2023/01/23 01:03:26 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr(unsigned long n, char *s, unsigned long i, char *arr_base)
{
	unsigned int	base;

	base = (unsigned long)printf_strlen(arr_base);
	if (n >= base)
	{
		ft_nbr(n / base, s, i - 1, arr_base);
		ft_nbr(n % base, s, i, arr_base);
	}
	else
		s[i] = arr_base[n];
}

char	*ft_itoa_uint(unsigned long n, char *arr_base)
{
	unsigned long	i;
	unsigned long	temp;
	char			*s;
	unsigned long	base;

	base = (unsigned long)printf_strlen(arr_base);
	i = 1;
	temp = n;
	while (n >= base)
	{
		i++;
		n /= base;
	}
	s = (char *)malloc((i + 1) * sizeof(char));
	if (!s)
		return (0);
	ft_nbr(temp, s, i - 1, arr_base);
	s[i] = '\0';
	return (s);
}
