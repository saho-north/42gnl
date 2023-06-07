/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:32:34 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/07 23:21:00 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	size_t	i;
	size_t	j;
	char	*test;

	//char	*file[100];
	// file[0] = "tests/test0.txt";
	// file[1] = "tests/test1.txt";
	// file[2] = "tests/test2.txt";
	// file[3] = "tests/test3.txt";
	// file[4] = "tests/test4.txt";
	// file[5] = "tests/test5.txt";
	// file[6] = "tests/test6.txt";
	// file[7] = "tests/test7.txt";
	// file[8] = "tests/test8.txt";
	// file[9] = "tests/test9.txt";
	test = "tests/nl";
	line = NULL;
	i = 9;
	while (i < 10)
	{
		fd = open(test, O_RDONLY);
		if (fd == -1)
		{
			printf("Error opening file: %s\n", test);
			return (1);
		}
		j = 0;
		while (j < 100)
		{
			line = get_next_line(fd);
			printf("file [%02zu]: #%s#\n\n", j, line);
			if (!line)
				break ;
			free(line);
			line = NULL;
			j++;
		}
		close(fd);
		i++;
	}
	return (0);
}
