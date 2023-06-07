/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:00:57 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/08 04:22:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*buffer;
	size_t	buf_size;
	size_t	i;

	buf_size = count * size;
	if (count > 0 && size > 0 && buf_size / count < size)
		return (NULL);
	buffer = (void *)malloc(buf_size);
	if (buffer)
	{
		i = 0;
		while (i < buf_size)
			buffer[i++] = '\0';
	}
	return (buffer);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	to_find;

	str = (char *)s;
	to_find = (char)c;
	while (str && *str)
	{
		if (*str == to_find)
			return (str);
		str++;
	}
	if (str && *str == to_find)
		return (str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptrdest;
	char	*ptrsrc;

	ptrdest = (char *)dst;
	ptrsrc = (char *)src;
	if (!ptrdest && !ptrsrc)
		return (NULL);
	while (n--)
		*(ptrdest++) = *(ptrsrc++);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	srclen;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if ((size_t)start >= srclen)
		len = 0;
	else if (len > srclen - (size_t)start)
		len = srclen - (size_t)start;
	substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	substr = ft_memcpy(substr, s + start, len);
	return (substr);
}
