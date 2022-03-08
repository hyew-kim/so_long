/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:52:57 by hyewkim           #+#    #+#             */
/*   Updated: 2021/10/04 17:53:02 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	char		*str;

	str = (char *)s1;
	i = 0;
	j = 0;
	if (s2[i] == 0)
		return (str);
	while (i + j < n && str[i])
	{
		j = 0;
		while (i + j < n && str[i + j] && str[i + j] == s2[j])
		{
			j++;
			if (s2[j] == 0)
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
