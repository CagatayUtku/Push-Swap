/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:00:49 by Cutku             #+#    #+#             */
/*   Updated: 2023/01/22 23:10:26 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_buff(int fd, char *sptr, int *flag)
{
	char	*buff;
	int		control;

	control = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!gnl_strchr(sptr, '\n') && control > 0)
	{
		control = read(fd, buff, BUFFER_SIZE);
		if (control == -1)
		{
			free(sptr);
			free(buff);
			return (NULL);
		}
		buff[control] = '\0';
		sptr = gnl_strjoin(sptr, buff);
	}
	*flag = control;
	free (buff);
	return (sptr);
}

char	*ft_get_line(char *sptr)
{
	char	*line;
	int		line_len;

	line_len = 0;
	if (!*sptr)
	{
		free(sptr);
		return (NULL);
	}
	while ((sptr[line_len] != '\n' && sptr[line_len] != '\0'))
		line_len++;
	line = gnl_substr(sptr, 0, line_len + 1);
	return (line);
}

char	*remain_part(char *sptr, int flag)
{
	char	*ptr;
	size_t	len;
	size_t	len_line;

	ptr = NULL;
	if (!*sptr)
	{
		free(sptr);
		return (NULL);
	}
	len = gnl_strlen(sptr);
	len_line = gnl_strchr(sptr, '\n') - sptr + 1;
	if (flag != 0)
		ptr = gnl_substr(sptr, len_line, len - len_line);
	free(sptr);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*sptr[MAX_FILES];
	char		*line;
	int			flag;

	flag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sptr[fd] = read_buff(fd, sptr[fd], &flag);
	if (!sptr[fd])
		return (NULL);
	if (*sptr[fd])
		line = ft_get_line(sptr[fd]);
	else
		line = (NULL);
	sptr[fd] = remain_part(sptr[fd], flag);
	return (line);
}
