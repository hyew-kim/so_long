/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 05:20:33 by hyewkim           #+#    #+#             */
/*   Updated: 2021/06/01 14:40:09 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	if (ptr == src)
		return (dest);
	while (n--)
	{
		*ptr = *((unsigned char *)src);
		if (*ptr == (unsigned char)c)
			return ((void *)(ptr + 1));
		ptr++;
		src++;
	}
	return (0);
}
