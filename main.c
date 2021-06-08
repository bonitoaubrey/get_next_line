/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:39:15 by agcolas           #+#    #+#             */
/*   Updated: 2021/06/08 08:44:05 by dav              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/*
** 1 : Une ligne a été lue
** 0 : La fin de fichier a été atteinte
** -1 : Une erreur est survenue
*/

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
