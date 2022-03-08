/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:09:56 by hyewkim           #+#    #+#             */
/*   Updated: 2021/06/08 17:42:41 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && is_set(s1[i], (char *)set))
		i++;
	j = ft_strlen(s1) - 1;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (j >= 0 && is_set(s1[j], (char *)set))
		j--;
	if (i > j)
		return (ft_strdup(""));
	res = ft_substr(s1, i, (j - i + 1));
	return (res);
}
