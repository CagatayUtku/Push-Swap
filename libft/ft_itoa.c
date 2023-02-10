/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:45:52 by Cutku             #+#    #+#             */
/*   Updated: 2022/10/19 23:43:04 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_putnbr_itoa(int n, char *s, int i)
{
	if (n == -2147483648)
	{
		s[0] = '-';
		s[1] = '2';
		n = 147483648;
		ft_putnbr_itoa(n, s, i);
	}
	else if (n < 0)
	{
		s[0] = '-';
		n = -n;
		ft_putnbr_itoa(n, s, i);
	}
	else if (n > 9)
	{
		ft_putnbr_itoa(n / 10, s, i - 1);
		ft_putnbr_itoa(n % 10, s, i);
	}
	else
		s[i] = n + 48;
}

char	*ft_itoa(int n)
{
	int		i;
	int		temp;
	char	*s;

	i = 1;
	temp = n;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		i++;
		n /= 10;
	}
	s = (char *)malloc((i + 1) * sizeof(char));
	if (!s)
		return (0);
	ft_putnbr_itoa(temp, s, i - 1);
	s[i] = '\0';
	return (s);
}
