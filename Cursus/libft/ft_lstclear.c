/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:47:13 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/14 18:09:20 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *lst;
	tmp2 = (*lst)->next;
	if (!tmp1)
		lst = NULL;
	else if (!tmp2)
	{
		ft_lstdelone(tmp1, del);
		lst = NULL;
	}
	else
	{
		while (tmp2)
		{
			ft_lstdelone(tmp1, del);
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		if (tmp1)
			ft_lstdelone(tmp1, del);
		lst = NULL;
	}
}
