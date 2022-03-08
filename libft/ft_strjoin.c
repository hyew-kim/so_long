/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:41:57 by hyewkim           #+#    #+#             */
/*   Updated: 2021/10/12 18:19:21 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char *dest, char const *src)
{
	int		i;
	char	*str;

	str = dest;
	while (*str)
	{
		str++;
	}
	i = 0;
	while (*src)
	{
		*str++ = *src++;
		i++;
	}
	*str = 0;
	return ;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens;
	char	*new_s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)malloc(sizeof(char) * (lens + 1));
	if (new_s == NULL)
		return (0);
	new_s[0] = '\0';
	ft_strcat(new_s, s1);
	ft_strcat(new_s, s2);
	return (new_s);
}
