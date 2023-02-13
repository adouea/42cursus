#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
int	main (int ac, char **av)
{
	char *str;
	
	if (ac < 2)
		return (0);
	int fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	if(str != NULL)
		free(str);
	close(fd);
}
