/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:30:47 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/22 15:19:24 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*backup[OPEN_MAX];
	int			read_byte;

	if (check(fd, line, &buf) == ERROR)
		return (ERROR);
	while (1)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte <= 0)
			break ;
		buf[read_byte] = 0;
		if (set_backup(&backup[fd], buf))
			return (ERROR);
		if (ft_strchr((const char *)backup[fd], '\n') >= 0)
		{
			free(buf);
			return (return_line_in_nl(&backup[fd], line, \
			 ft_strchr((const char *)backup[fd], '\n')));
		}
	}
	free(buf);
	if (read_byte < 0)
		return (ERROR);
	return (return_line(&backup[fd], line));
}

int	check(int fd, char **line, char **buf)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX || !line)
		return (ERROR);
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (ERROR);
	return (0);
}

int	set_backup(char **backup_fd, char *buf)
{
	char	*tmp;

	if (*backup_fd)
		tmp = ft_strjoin(*backup_fd, buf);
	else
		tmp = ft_strdup((const char *)buf);
	if (tmp == NULL)
	{
		free(buf);
		return (ERROR);
	}
	if (*backup_fd)
		free(*backup_fd);
	*backup_fd = tmp;
	return (E_O_F);
}
