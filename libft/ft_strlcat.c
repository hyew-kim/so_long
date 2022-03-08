/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:52:22 by hyewkim           #+#    #+#             */
/*   Updated: 2021/06/07 21:07:59 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	len_s;
	size_t	len_d;
	size_t	i;

	if (!dest && !src)
		return (0);
	len_s = ft_strlen(src);
	len_d = ft_strlen(dest);
	if (!len)
		return (len_s);
	if (len <= len_d)
		return (len_s + len);
	i = 0;
	while (len_d + i < len - 1 && src[i])
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = 0;
	return (len_s + len_d);
}
