/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:50:13 by Cutku             #+#    #+#             */
/*   Updated: 2023/01/22 23:10:26 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (s && s[i] == c)
		return (s + i);
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	unsigned int	i;
	unsigned int	j;
	char			*temp;

	i = 0;
	j = 0;
	len_s1 = gnl_strlen(s1);
	len_s2 = gnl_strlen(s2);
	temp = (char *)malloc((len_s1 + len_s2 +1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		temp[i++] = s2[j++];
	temp[i] = '\0';
	free(s1);
	return (temp);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	size;

	if (!s)
		return (0);
	i = 0;
	if (start > (unsigned int)gnl_strlen(s))
		len = 0;
	size = (size_t)gnl_strlen(s) - (size_t)start;
	if (len > size)
		len = size;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (i < len && start < (size_t)gnl_strlen(s))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
