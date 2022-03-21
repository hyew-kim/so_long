#include "so_long.h"

int	readMap(t_map *ptr, int fd)
{
	int		gnl_return;
	char	*mapLine;
	char	*line;

	line = NULL;
	mapLine = NULL;
	while (1)
	{
		gnl_return = get_next_line(fd, &line);
		if (gnl_return != SUCCUESS)
			break ;
		if (checkLine(line, ptr))
		{
			printf("%s\n", line);
			closeWithError(fd, "Wrong map2\n");
		}
		line = ft_strjoin(line, "\n");
		mapLine = ft_strjoin(mapLine, line);
		free(line);
		line = NULL;
	}
	if (gnl_return == ERROR)
		return (1);
	close(fd);
	ptr->map = ft_split(mapLine, '\n');
	free(mapLine);
	return (0);
}

int	checkLine(char *line, t_map *ptr)
{
	int	idx = 0;
	int len = 0;

	idx = -1;
	len = ft_strlen(line);
	if (ptr->mapWidth && ptr->mapWidth != len)
		return (1);
	ptr->mapWidth = len;
	(ptr->mapHeight)++;
	while (++idx < len)
	{
		if (ft_strchr("01CEP", (int)line[idx]) < 0)
			return (1);
		if (line[idx] == 'P')
		{
			(ptr->player)++;
			ptr->x = ptr->mapHeight;
			ptr->y = idx;
		}
		else if (line[idx] == 'C')
			(ptr->collect)++;
		else if (line[idx] == 'E')
			(ptr->exit)++;
	}
	return (0);
}

int	checkMap(t_map *ptr)
{
	int	i;
	int	j;

	if (!ptr->map || ptr->player != 1 || ptr->exit < 1 || ptr->collect < 1)
		return (1);
	i = -1;
	while (++i < ptr->mapHeight)
	{
		j = -1;
		while (++j < ptr->mapWidth)
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
		}
	}
	return (0);
}

void	move(t_map *ptr, int x,int y)
{
    if (ptr->map[x][y] == '1')
        return ;
    (ptr->move)++;
    ft_putnbr_fd(ptr->move, 1);
    ft_putchar_fd('\n', 1);
    if (ptr->map[x][y] == 'C')
    {
        (ptr->collect)--;
        ptr->map[x][y] = '0';
    }
    if (ptr->map[x][y] == 'E' && !ptr->collect)
    {
        ft_putstr_fd("Game Clear", 1);
        exit(EXIT_SUCCESS);
    }
    ptr-> x = x;
    ptr-> y = y;
}