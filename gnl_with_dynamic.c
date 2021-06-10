#include "get_next_line.h"

static char	*ft_new_line(char **line, char **mmry)
{
	char	*first_line;

	first_line = *line;
	*line = ft_strjoin(*line, *mmry);
	if (!(*line))
		return (NULL);
	free(first_line);
	return (*mmry);
}

static char	*rem_check(char **mmry, char **line)
{
	char	*buff;

	buff = NULL;
	if (*mmry)
	{
		buff = ft_strchr(*mmry, '\n');
		if (buff)
		{
			*buff = '\0';
			ft_new_line(line, mmry);
			ft_strcpy(*mmry, ++buff);
		}
		else
			ft_new_line(line, mmry);
	}
	return (buff);
}

static int	ft_resultult_check(int rd)
{
	if (rd == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*mmry;
	char		*temp;
	int			rd;

	if (BUFFER_SIZE < 0 || fd < 0 || fd == 1 || fd == 2 || (read(fd, mmry, 0)) < 0)
		return (-1);
	if (!mmry)
	{
		mmry = (char *)malloc(BUFFER_SIZE + 1);
		if (!mmry)
			return (-1);
	}
	*line = ft_strdup("");
	if (!(*line))
	 	return (-1);
	rd = 1;
	temp = rem_check(&mmry, line);
	while (!temp && rd)
	{
		rd = read(fd, mmry, BUFFER_SIZE);
		mmry[rd] = '\0';
		temp = rem_check(&mmry, line);
	}
	return (ft_resultult_check(rd));
}
