/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:40:03 by Cutku             #+#    #+#             */
/*   Updated: 2022/10/20 05:15:06 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	head;
	unsigned int	tail;
	char			*ptr;

	if (!s1 || !set)
		return (0);
	head = 0;
	tail = (unsigned int)ft_strlen(s1);
	while (s1[head] && ft_strchr(set, s1[head]))
		head++;
	while (tail > head && ft_strchr(set, s1[tail - 1]))
		tail--;
	ptr = (char *)malloc((tail - head + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (head + i < tail)
	{
		ptr[i] = s1[head + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
