/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:03:52 by hyewkim           #+#    #+#             */
/*   Updated: 2021/10/12 20:39:45 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	issep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	cal_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (issep(s[i], c))
			i++;
		else
		{
			len++;
			while (s[i] && !issep(s[i], c))
				i++;
		}
	}
	return (len);
}

static int	make_res_j(char const *s, char **res_j, int len, int i)
{
	int		k;

	*res_j = (char *)malloc(sizeof(char) * (len + 1));
	if (res_j == NULL)
		return (1);
	k = 0;
	while (k < len)
	{
		(*res_j)[k] = s[(i - len) + k];
		k++;
	}
	(*res_j)[k] = 0;
	return (0);
}

static void	split_string(char const *s, char c, char **res)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (s[i] && j < cal_len(s, c))
	{
		len = 0;
		while (s[i] && issep(s[i], c))
			i++;
		while (s[i] && !(issep(s[i], c)))
		{
			len++;
			i++;
		}
		if (make_res_j(s, &res[j], len, i))
		{	
			while (j--)
				free(res[j]);
			return ;
		}
		j++;
	}
	res[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (s)
	{
		res = (char **)malloc(sizeof(char *) * (cal_len(s, c) + 1));
		if (res == NULL)
			return (0);
		split_string(s, c, res);
		return (res);
	}
	return (NULL);
}
