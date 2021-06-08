#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);

#endif
