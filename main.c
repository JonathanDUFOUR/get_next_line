/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:35:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/21 17:28:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;

	if (ac == 2)
	{
		line = NULL;
		fd = open(av[1], O_RDONLY);
		if (fd != ERROR)
		{
			ret = get_next_line(fd, &line);
			while (ret == LINE_READ)
			{
				printf("\033[33mLine read:\033[0m\n%s\n", line);
				ret = get_next_line(fd, &line);
			}
			if (ret == EOF_REACHED)
				printf("\033[33mEOF reached:\033[0m\n%s\n", line);
			else
				printf("Error encountered\n");
			close(fd);
			free(line);
		}
		else
			printf("Open error\n");
	}
	return (EXIT_SUCCESS);
}
