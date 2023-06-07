/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:06:36 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/08 01:52:17 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_next_line(char **buffered_text)
{
	char	*next_line;
	char	*marker;
	char	*tmp;
	size_t	i;

	marker = ft_strchr(*buffered_text, '\n');
	if (!marker)
		marker = ft_strchr(*buffered_text, '\0');
	i = marker - *buffered_text + 1;
	next_line = ft_substr(*buffered_text, 0, i);
	if (!next_line)
		return (NULL);
	if (*marker != '\0' && *marker + 1 != '\0')
	{
		//printf("if marker: %s\n", marker);
		tmp = *buffered_text;
		*buffered_text = ft_substr(tmp, i + 1, ft_strlen(tmp) - i - 1);
		free(tmp);
		if (!*buffered_text)
			return (NULL);
	}
	else
	{
		//printf("else marker: %s\n", marker);
		free(*buffered_text);
		*buffered_text = NULL;
		return (NULL);
	}
	return (next_line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, len1);
	ft_memcpy(dst + len1, s2, len2);
	return (dst);
}

char	*ft_free_after_join(char *buffered_text, char *read_buffer)
{
	char	*tmp;

	tmp = ft_strjoin(buffered_text, read_buffer);
	return (tmp);
}

char	*ft_get_buffered_text(int fd, char **buffered_text)
{
	char	*read_buffer;
	char	*tmp;
	ssize_t	bytes_read;

	read_buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(*buffered_text, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (*buffered_text)
				free(*buffered_text);
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		if (!*buffered_text)
			tmp = ft_strdup(read_buffer);
		else
			tmp = ft_free_after_join(*buffered_text, read_buffer);
		if (*buffered_text)
			free(*buffered_text);
		if (!tmp)
			return (NULL);
		*buffered_text = tmp;
	}
	if (read_buffer)
		free(read_buffer);
	if (bytes_read == 0 && !*buffered_text)
		return (NULL);
	return (*buffered_text);
}

char	*get_next_line(int fd)
{
	static char	*buffered_text;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	//printf("1. buffered_text: %s\n", buffered_text);
	buffered_text = ft_get_buffered_text(fd, &buffered_text);
	if (!buffered_text)
		return (NULL);
	//printf("2. buffered_text: %s\n", buffered_text);
	next_line = ft_trim_next_line(&buffered_text);
	if (!next_line && buffered_text)
	{
		next_line = ft_strdup(buffered_text);
		free(buffered_text);
		buffered_text = NULL;
	}
	//printf("3. next_line: %s\n", next_line);
	return (next_line);
}
