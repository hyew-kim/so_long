/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:08:03 by hyewkim           #+#    #+#             */
/*   Updated: 2021/06/06 15:33:03 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*find;

	if (!lst && !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	find = *lst;
	find = ft_lstlast(*lst);
	find->next = new;
	return ;
}
