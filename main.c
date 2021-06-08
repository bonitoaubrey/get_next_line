#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		ret;
	int		i;

	ret = 1;
	i = 1;
	fd = open("file.txt", O_RDONLY);
	line = NULL;
	while (ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		printf("** Line %d **\n", i);
		if (ret == 1)
			printf("No problem");
		if (ret == 0)
			printf("End of file");
		if (ret == -1)
			printf("Error");
		printf("\nLine *%s*\n\n", line);
		if (line)
			free(line);
		i++;
	}
	char *sex = ft_strdup("bite");
	free(sex);
	close(fd);
	return (0);
}
