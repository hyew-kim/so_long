/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:45:10 by hyewkim           #+#    #+#             */
/*   Updated: 2021/05/14 20:22:52 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	i = ft_strlen(str);
	ptr = (char *)str + i;
	while (i >= 0)
	{
		if ((*ptr) == (unsigned char)c)
		{
			return (ptr);
		}
		ptr--;
		i--;
	}
	return (NULL);
}
