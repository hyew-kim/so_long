/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:29:22 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/18 01:14:26 by hyewonkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		gnl_return;
	char	*mapLine;
	t_map	ptr;

	checkInput(argc, argv);
	init(&ptr);
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	mapLine = NULL;
	while (1)
	{
		gnl_return = get_next_line(fd, &line);
		if (gnl_return != SUCCUESS)
			break;
		if (checkLine(line, &ptr))
			closeWithError(fd, "Wrong map\n");
		line = ft_strjoin(line, "\n");
		mapLine = ft_strjoin(mapLine, line);
		free(line);
		line = NULL;
	}
	if (gnl_return == ERROR)
		printError("Fail map reading\n");
	close(fd);
	ptr.map = ft_split(mapLine, '\n');
	free(mapLine);
	if (checkMap(&ptr))
		printError("Wrong map\n");
	mlx_main(&ptr);
	return (0);
}
void printError(char *errorMessage)
{
	//perror(errorMessage);
	ft_putstr_fd(errorMessage, 1);
	exit(EXIT_FAILURE);
}
void closeWithError (int fd, char *errorMessage)
{
	close(fd);
	printError(errorMessage);
}
