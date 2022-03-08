/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:58:40 by hyewkim           #+#    #+#             */
/*   Updated: 2021/10/04 19:06:23 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cal_len(int nbr)
{
	size_t			len;

	if (nbr < 0)
		nbr *= -1;
	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	*make_rev_nbr(int n)
{
	char			*tmp;
	size_t			len;
	size_t			i;

	len = cal_len(n);
	tmp = (char *)malloc(sizeof(char) * (len + 2));
	if (tmp == NULL)
		return (NULL);
	if (n < 0)
		n *= -1;
	i = 0;
	while (i < len)
	{
		tmp[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

static char	*make_itoa(int n, size_t len)
{
	char			*res;
	char			*tmp;
	size_t			i;
	size_t			j;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	tmp = make_rev_nbr(n);
	if (tmp == NULL)
	{
		free(res);
		return (NULL);
	}
	if (n < 0)
		res[0] = '-';
	i = 0;
	if (n > 0)
		i = -1;
	j = ft_strlen(tmp) - 1;
	while (++i < len)
		res[i] = tmp[j--];
	res[i] = 0;
	free(tmp);
	return (res);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n > 0)
		len = cal_len(n);
	else
		len = cal_len(n) + 1;
	str = make_itoa(n, len);
	return (str);
}
