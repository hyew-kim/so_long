/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:29:22 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/21 17:51:00 by hyewonkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	int		fd;
	t_map	ptr;

	checkInput(argc, argv);
	init(&ptr);
	fd = open(argv[1], O_RDONLY);
	printf("init: %d\n", ptr.mapWidth);
	if (readMap(&ptr, fd))
		printError("Fail map reading\n");
	if (checkMap(&ptr))
		printError("Wrong map1\n");
	mlx_main(&ptr);
	return (0);
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
	ptr->mapWidth = 0;
	ptr->mapHeight = 0;
	ptr->exit = 0;
	ptr->map = NULL;
	ptr->move = 0;
	return;
}

void printError(char *errorMessage)
{
	ft_putstr_fd(errorMessage, 2);
	exit(EXIT_FAILURE);
}

void closeWithError (int fd, char *errorMessage)
{
	close(fd);
	printError(errorMessage);
}
