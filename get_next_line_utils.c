#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*new_str;
	int		i;

	new_str = malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (s[++i])
		new_str[i] = s[i];
	new_str[i] = '\0';
	return (new_str);
}

int	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		len;

	if (!s1)
	{
		dst = ft_strdup(s2);
		return (dst);
	}	
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc((sizeof(char) * len) + 1);
	if (!dst)
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcpy(&dst[ft_strlen(s1)], s2);
	return (dst);
}
