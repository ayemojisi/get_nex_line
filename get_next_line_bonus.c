/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:47:42 by iergun            #+#    #+#             */
/*   Updated: 2023/03/07 03:47:44 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_move_str(char **str, size_t n)
{
	char	*old;
	size_t	len;

	old = *str;
	len = ft_strlen(*str) - n;
	if (len == 0)
		*str = NULL;
	else
		*str = ft_substr(old, n, len);
	free(old);
	return (*str);
}

char	*ft_strappend(char **str, char *str2)
{
	char	*old;

	old = *str;
	*str = ft_strjoin(old, str2);
	if (old)
		free(old);
	return (0);
}

char	*get_data(char **backup, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		readed_byte;

	readed_byte = 1;
	while (!(ft_strchr(*backup, '\n')) && readed_byte > 0)
	{
		readed_byte = read(fd, buffer, BUFFER_SIZE);
		buffer[readed_byte] = 0;
		if (readed_byte <= 0)
			break ;
		ft_strappend(backup, buffer);
	}
	return (*backup);
}

char	*get_line(char **str)
{
	char	*line;
	size_t	new_len;

	if (ft_strchr(*str, '\n'))
	{
		new_len = ft_strchr(*str, '\n') - (*str);
		line = ft_substr(*str, 0, new_len);
		ft_move_str(str, new_len);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	get_data(&buffer[fd], fd);
	line = get_line(&buffer[fd]);
	if (line == NULL)
	{
		line = ft_strdup(buffer[fd]);
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
