/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:32:34 by sakitaha          #+#    #+#             */
/*   Updated: 2023/05/31 05:05:23 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	print_error_main(short error_code)
{
	char	*error_message[3];

	error_message[0] = "Error: Invalid number of arguments\n";
	error_message[1] = "Error: Failed to open the file.\n";
	error_message[2] = "Error: Failed to read the file.\n";
	ft_putstr(error_message[error_code]);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*readline;

	if (argc != 2)
	{
		print_error_main(0);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error_main(1);
		return (1);
	}
	while (readline = get_next_readline(fd))
	{
		if (!readline)
		{
			print_error_main(2);
			return (1);
		}
		else
		{
			ft_putstr(readline);
		}
	}
	close(fd);
	return (0);
}
