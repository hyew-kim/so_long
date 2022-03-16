/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:29:22 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/17 02:09:28 by hyewonkim        ###   ########.fr       */
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
	char *tmp;

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
	if (checkLine(line, &ptr))
		closeWithError(fd, "Wrong map\n");
	mapLine = ft_strjoin(mapLine, line);
	free(line);
	close(fd);
	ptr.map = ft_split(mapLine, '\n'); //split으로 만든거니 free 해줘야해!!!!
	free(mapLine);
	if (checkMap(&ptr))
		printError("Wrong map\n");
	return (0);
}
void printError(const char *errorMessage)
{
	perror(errorMessage);
	exit(EXIT_FAILURE);
}
void closeWithError (int fd, const char *errorMessage)
{
	close(fd);
	printError(errorMessage);
}

void checkInput(int argc, char *argv[])
{
	if (argc < 2 || ft_strnstr((const char *)argv[1], ".ber", ft_strlen((const char *)argv[1])) == NULL)
		printError("Wrong input\n");
	return;
}

void init(t_map *ptr)
{
	ptr->player = 0;
	ptr->collect = 0;
	ptr->blank = 0;
	ptr->mapWidth = 0;
	ptr->mapHeight = 0;
	ptr->exit = 0;
	ptr->map = NULL;
	return;
}

int checkLine(char *line, t_map *ptr)
{
	int idx = -1;
	int len = ft_strlen(line);
	if (ptr->mapWidth && ptr->mapWidth != len)
		return (1);
	ptr->mapWidth = len;
	(ptr->mapHeight)++;
	while (++idx < len)
	{
		if (ft_strchr("01CEP", (int)line[idx]) < 0)
			return (1);
		if (line[idx] == 'P')
			(ptr->player)++;
		else if (line[idx] == 'C')
			(ptr->collect)++;
		else if (line[idx] == 'E')
			(ptr->exit)++;
	}
	return (0);
}

int checkMap(t_map *ptr)
{
	int i;
	int j;

	if (!ptr->map || ptr->player != 1 || ptr->exit < 1 || ptr->collect < 1)
		return (1);
	i = 0;
	while (i < ptr->mapHeight)
	{
		j = 0;
		while (j < ptr->mapWidth)
		{
			if (i == 0 || i == ptr->mapHeight - 1)
			{
				if (ptr->map[i][j] != '1')
					return (1);
			}
			else if (j == 0 || j == ptr->mapWidth - 1)
			{
				if (ptr->map[i][j] != '1')
					return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}
