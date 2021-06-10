#include "get_next_line.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *) s;
	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	j = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	while (j > i)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof (*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
		str[i++] = s2[j];
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
