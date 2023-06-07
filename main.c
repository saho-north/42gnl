/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:32:34 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/07 11:23:24 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd1;
	int		i;

	// int		fd2;
	// int		fd3;
	fd1 = open("tests/test_001.txt", O_RDONLY);
	// fd2 = open("tests/test2.txt", O_RDONLY);
	// fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	// while (i < 7)
	// {
	// 	line = get_next_line(fd1);
	// 	printf("line [%02d]: %s", i, line);
	// 	free(line);
	// 	// line = get_next_line(fd2);
	// 	// printf("line [%02d]: %s", i, line);
	// 	// free(line);
	// 	// line = get_next_line(fd3);
	// 	// printf("line [%02d]: %s", i, line);
	// 	// free(line);
	// 	// i++;
	// }
	line = get_next_line(fd1);
	printf("line [%02d]: %s", i, line);
	free(line);
	close(fd1);
	// close(fd2);
	// close(fd3);
	return (0);
}
