/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:00:23 by hyewkim           #+#    #+#             */
/*   Updated: 2021/10/12 18:25:30 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *ptr, int c)
{
	int		i;
	char	*str;

	str = (char *)ptr;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == (unsigned char)c)
				return (i);
			i++;
		}
	}
	return (-1);
}
