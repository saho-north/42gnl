/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:06:36 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/10 08:05:47 by sakitaha         ###   ########.fr       */
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

	if (!read_buffer)
		return (NULL);
	if (!buffered_text)
	{
		dst = ft_substr(read_buffer, 0, ft_strlen(read_buffer));
		if (!dst)
			return (NULL);
		return (dst);
	}
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
		read_buffer[bytes_read] = '\0';
		if (bytes_read > 0)
			*buffered_text = strjoin_plus(*buffered_text, read_buffer);
		if (!*buffered_text)
			break ;
	}
	free(read_buffer);
	if (!*buffered_text || !ft_strlen(*buffered_text) || bytes_read < 0)
	{
		if (*buffered_text)
			free(*buffered_text);
		return (NULL);
	}
	return (*buffered_text);
}

char	*get_next_line(int fd)
{
	static char	*buffered_text[FD_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffered_text[fd] = read_from_file(fd, &buffered_text[fd]);
	if (!buffered_text[fd])
		return (NULL);
	next_line = extract_next_line(&buffered_text[fd]);
	if (!next_line)
		return (NULL);
	return (next_line);
}
