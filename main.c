#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line))
		free(line);
	return (EXIT_SUCCESS);
}
