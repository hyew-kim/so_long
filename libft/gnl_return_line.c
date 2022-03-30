/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_return_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:12:11 by hyewkim           #+#    #+#             */
/*   Updated: 2022/03/22 15:14:58 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	return_line(char **backup_fd, char **line)
{
	int	idx_nl;

	idx_nl = ft_strchr((const char *)*backup_fd, '\n');
	if (*backup_fd && (idx_nl >= 0))
		return (return_line_in_nl(backup_fd, line, idx_nl));
	else
	{
		if (*backup_fd)
		{
			*line = *backup_fd;
			*backup_fd = 0;
		}
		else
		{
			*line = ft_strdup((const char *)"");
			if (!(*line))
				return (ERROR);
		}
		return (E_O_F);
	}
}

int	return_line_in_nl(char **backup_fd, char **line, int idx_nl)
{
	char	*tmp;

	(*backup_fd)[idx_nl] = 0;
	if (dup_line(&tmp, backup_fd, line))
		return (ERROR);
	if ((*backup_fd)[idx_nl + 1])
	{
		tmp = ft_strdup((const char *)(*backup_fd + idx_nl + 1));
		if (!tmp)
		{
			free(*backup_fd);
			*backup_fd = 0;
			return (ERROR);
		}
		free(*backup_fd);
		*backup_fd = tmp;
		return (SUCCUESS);
	}
	if (*backup_fd)
	{
		free(*backup_fd);
		*backup_fd = 0;
	}
	return (SUCCUESS);
}

int	dup_line(char **tmp, char **backup_fd, char **line)
{
	*tmp = ft_strdup((const char *)*backup_fd);
	if (!(*tmp))
		return (ERROR);
	*line = *tmp;
	return (0);
}
