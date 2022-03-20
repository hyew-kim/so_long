#include "so_long.h"

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
			if (ptr->map[i][j] == 'P')
			{
				ptr->x = i;
				ptr->y = j;
			}
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
