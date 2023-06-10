/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:06:36 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/10 09:44:40 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_next_line(char **buffered_text)
{
	char	*next_line;
	char	*marker;
	char	*tmp;

	marker = ft_strchr(*buffered_text, '\n');
	if (marker)
		next_line = ft_substr(*buffered_text, 0, marker - *buffered_text + 1);
	if (!marker)
		next_line = ft_substr(*buffered_text, 0, ft_strlen(*buffered_text));
	if (!next_line || !marker)
	{
		free(*buffered_text);
		*buffered_text = NULL;
		return (next_line);
	}
	tmp = *buffered_text;
	*buffered_text = ft_substr(marker + 1, 0, ft_strlen(marker + 1));
	free(tmp);
	if (!*buffered_text)
		return (NULL);
	return (next_line);
}

char	*strjoin_plus(char *buffered_text, char *read_buffer)
{
	char	*dst;
	size_t	len1;
	size_t	len2;

	if (!buffered_text || !read_buffer)
		return (NULL);
	len1 = ft_strlen(buffered_text);
	len2 = ft_strlen(read_buffer);
	dst = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!dst)
	{
		free(buffered_text);
		return (NULL);
	}
	ft_memcpy(dst, buffered_text, len1);
	ft_memcpy(dst + len1, read_buffer, len2);
	free(buffered_text);
	return (dst);
}

char	*read_from_file(int fd, char **buffered_text)
{
	char	*read_buffer;
	ssize_t	bytes_read;

	read_buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(*buffered_text, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		read_buffer[bytes_read] = '\0';
		*buffered_text = strjoin_plus(*buffered_text, read_buffer);
		if (!*buffered_text)
			break ;
	}
	free(read_buffer);
	if (!*buffered_text || !ft_strlen(*buffered_text) || bytes_read < 0)
		return (NULL);
	return (*buffered_text);
}

char	*get_next_line(int fd)
{
	static char	*buffered_text[FD_MAX];
	char		*tmp;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > ULONG_MAX)
		return (NULL);
	if (!buffered_text[fd])
	{
		buffered_text[fd] = (char *)ft_calloc(1, sizeof(char));
		if (!buffered_text[fd])
			return (NULL);
	}
	tmp = read_from_file(fd, &buffered_text[fd]);
	if (!tmp)
	{
		if (buffered_text[fd])
		{
			free(buffered_text[fd]);
			buffered_text[fd] = NULL;
		}
		return (NULL);
	}
	buffered_text[fd] = tmp;
	return (extract_next_line(&buffered_text[fd]));
}
