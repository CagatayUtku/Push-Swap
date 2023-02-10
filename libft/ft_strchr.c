/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:39:47 by Cutku             #+#    #+#             */
/*   Updated: 2022/10/18 01:47:02 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char				*ptr;
	unsigned char		a;
	unsigned int		i;

	i = 0;
	a = c;
	ptr = (char *)s;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == a)
			return (ptr + i);
		i++;
	}
	if (ptr[i] == a)
		return (ptr + i);
	return (0);
}
