/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:06:36 by sakitaha          #+#    #+#             */
/*   Updated: 2023/05/30 00:46:01 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
fd:  The file descriptor to read from
read, malloc, free

Return value
Read line:  correct behavior
NULL: there is nothing else to read, or an error occurred
Description
Write a function that returns a line read from a
file descriptor
 */

// • Repeated calls (e.g.,
// 		using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor,
// 	one line at a time.
// // • Your function should return the line that was read.
// // If there is nothing else to read or if an error occurred,
// 	it should return NULL.
//
// • Make sure that your function works as expected both when reading a file and when reading from the standard input.
//
// • Please note that the returned line should include the terminating \n character,
// 	except if the end of file was reached and does not end with a \n character.
//
// • Your header file get_next_line.h must at least contain the prototype of the get_next_line() function.
// // • Add all the helper functions you need in the get_next_line_utils.c file.

char	*get_next_line(int fd)
{
	static char	*readline;
	char		buf[BUFFER_SIZE + 1];
	int			i;

	readline = read(fd, buf, BUFFER_SIZE);
	i = 0;
}
