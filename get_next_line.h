#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# if BUFFER_SIZE < 0
#  define SIZE 0

# elif BUFFER_SIZE > 1000000000
#  define SIZE 0

# else
#  define SIZE BUFFER_SIZE

# endif

# include <fcntl.h> // для функции open
# include <stdlib.h> // для функции free
# include <unistd.h> // для функции read
# include <stdio.h> // для функции printf

int		get_next_line(int fd, char **line);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif