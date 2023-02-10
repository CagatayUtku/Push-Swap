/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:21:49 by Cutku             #+#    #+#             */
/*   Updated: 2022/10/22 03:20:21 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*ptr_dst;
	char		*ptr_src;

	i = 0;
	if (!dst && !src)
		return (NULL);
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (ptr_dst < ptr_src)
	{
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
		return (dst);
	}
	while (len > 0)
	{
		ptr_dst[len - 1] = ptr_src[len - 1];
		len--;
	}
	return (dst);
}
