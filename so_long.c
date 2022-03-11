/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:29:22 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/11 23:40:07 by hyewonkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	int fd;
	char *line;
	int gnl_return;
	t_map map;

	check_input(argc, argv);
	init(&map);
	fd = open(argv[1], O_RDONLY);
	int height = 0;
	int width = 0;
	while (1)
	{
		line = NULL;
		gnl_return = 1;
		gnl_return = get_next_line(fd, &line) > 0;
		if (gnl_return == SUCCUESS)
		{
			width = ft_strlen(line);
			++height;
			count_object(line, &map);
		} 
		else
			break;
	}
	ft_putnbr_fd(height, 1);
	free(line);
	close(fd);
	if (gnl_return == ERROR)
		perror("Error: map reading\n");
	check_object_count(&map);
	return (0);
}

void check_input(int argc, char *argv[])
{
	if (argc < 2 || ft_strnstr((const char *)argv[1], ".ber", ft_strlen((const char *)argv[1])) == NULL)
	{
		perror("Error: wrong input\n");
		exit(EXIT_FAILURE);
	}
	return;
}

void init(t_map *map)
{
	map->player = 0;
	map->collect = 0;
	map->blank = 0;
	map->wall_low = 0;
	map->wall_coulmn = 0;
	map->exit = 0;
	return;
}

void count_object(char *line, t_map *map)
{
	int idx = -1;
	int len = ft_strlen(line);
	while (++idx < len)
	{
		if (line[idx] == 'P')
			(map->player)++;
		else if (line[idx] == 'C')
			(map->collect)++;
		else if (line[idx] == 'E')
			(map->exit)++;
	}
}
// 한 줄씩 p, c, e세기, 다 읽어서 최소 개수 만족하는지 확인하기
//직사각형인지 파악하기
//가로: 첫줄 개수
//세로: \n 개수

void check_object_count(t_map *map)
{
	ft_putnbr_fd(map->player, 1);
	ft_putnbr_fd(map->exit, 1);
	ft_putnbr_fd(map->collect, 1);
	if (map->player < 1 || map->exit < 1 || map->collect < 1)
	{
		perror("Error: wrong map\n");
		exit(EXIT_FAILURE);
	}
}
