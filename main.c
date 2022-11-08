#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line))
	{
		printf("[%s]\n", line);
		free(line);
	}
	return (EXIT_SUCCESS);
}
