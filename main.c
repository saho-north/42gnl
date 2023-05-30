/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:32:34 by sakitaha          #+#    #+#             */
/*   Updated: 2023/05/30 14:55:06 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*readline;

	if (argc != 2)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Failed to open the file.\n");
		return (1);
	}
	readline = get_next_readline(fd);
	if (!readline)
	{
		printf("Error: Failed to read the file.\n");
		return (1);
	}
	else
	{
		printf("read: %s\n", readline);
	}
	close(fd);
	return (0);
}
