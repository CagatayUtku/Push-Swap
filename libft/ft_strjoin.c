/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:12:49 by Cutku             #+#    #+#             */
/*   Updated: 2022/10/20 00:38:28 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*dst;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc((len +1) * sizeof(char));
	if (!dst)
		return (0);
	ft_memcpy(dst, s1, ft_strlen(s1));
	ft_memcpy(&dst[ft_strlen(s1)], s2, ft_strlen(s2));
	dst[len] = '\0';
	return (dst);
}
