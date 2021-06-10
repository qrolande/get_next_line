#include "get_next_line.h"

static char	*rem_check(char *mmry, char **line)
{
	char	*buff;

	buff = ft_strchr(mmry, '\n');
	if ((!*mmry))
		return (buff);
	if (buff)
	{
		*buff++ = '\0';
		*line = ft_strjoin(*line, mmry);
		if (!(*line))
			return (NULL);
		ft_strcpy(mmry, buff);
	}
	else
	{
		*line = ft_strjoin(*line, mmry);
		if (!(*line))
			return (NULL);
	}
	return (buff);
}

int	get_next_line(int fd, char **line)
{
	static char	mmry[SIZE + 1];
	char		*temp;
	int			rd;

	if (SIZE < 1 || fd < 0  || (read(fd, mmry, 0)) < 0)
		return (-1);
	*line = ft_strdup("");
	if (!(*line))
		return (-1);
	rd = 1;
	temp = rem_check(mmry, line);
	while (!temp && rd)
	{
		rd = read(fd, mmry, SIZE);
		mmry[rd] = '\0';
		temp = rem_check(mmry, line);
	}
	if (rd == 0)
		return (0);
	else
		return (1);
}
