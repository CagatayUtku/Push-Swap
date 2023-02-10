/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:22:00 by Cutku             #+#    #+#             */
/*   Updated: 2022/10/22 02:05:29 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	size;

	if (!s)
		return (0);
	i = 0;
	if (start > (unsigned int)ft_strlen(s))
		len = 0;
	size = (size_t)ft_strlen(s) - (size_t)start;
	if (len > size)
		len = size;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (i < len && start < (size_t)ft_strlen(s))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
