#include "get_next_line.h"

int	split_buffer(char *buff, char *save, int reader)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (buff[i] == '\n')
	{
		reader = 1;
		buff[i++] = '\0';
	}
	while (buff[i])
	{
		save[j++] = buff[i];
		buff[i++] = '\0';
	}
	save[j] = '\0';
	return (reader);
}

int	get_save(char **line, char *buff, char *save, int reader)
{
	char	*tmp;

	ft_strcpy(buff, save);
	reader = split_buffer(buff, save, reader);
	tmp = ft_strdup(buff);
	free(*line);
	*line = tmp;
	return (reader);
}

int	reading(char **line, char *save, int reader, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		i;

	i = 1;
	while (i > 0 && reader == 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		reader = split_buffer(buff, save, reader);
		tmp = ft_strjoin(*line, buff);
		free(*line);
		*line = tmp;
	}
	return (reader);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	save[BUFFER_SIZE + 1];
	int			reader;

	reader = 0;
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	*line = ft_strdup("");
	if (ft_strlen(save) > 0)
		reader = get_save(line, buff, save, reader);
	if (reader != 1)
		reader = reading(line, save, reader, fd);
	return (reader);
}
