/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:04:37 by Cutku             #+#    #+#             */
/*   Updated: 2022/10/18 22:49:02 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	if (!dst && !src)
		return (0);
	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)dst;
	while (i < n)
	{
		*((char *)ptr2 + i) = *((char *)ptr1 + i);
		i++;
	}
	return (dst);
}
