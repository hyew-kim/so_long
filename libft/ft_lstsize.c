/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:11:09 by hyewkim           #+#    #+#             */
/*   Updated: 2021/06/04 15:35:15 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*find;

	if (!lst)
		return (0);
	cnt = 1;
	find = lst;
	while (find->next != NULL)
	{
		cnt++;
		find = find->next;
	}
	return (cnt);
}
