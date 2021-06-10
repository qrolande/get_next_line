/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:40:15 by qrolande          #+#    #+#             */
/*   Updated: 2021/06/09 20:08:34 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		res;
	int		i = 1;

	fd = open("/Users/qrolande/Desktop/gnl/test.txt", O_RDONLY);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		printf("%2d) res = %d |%s|\n", i, res, line);
	//	free(line);
		i++;
	}
	
	printf("%2d) res = %d |%s|\n", i, res, line);
	//free(line);

	// while (1)
	// 	;

	return (0);
}
