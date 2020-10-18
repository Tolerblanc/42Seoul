/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:15:45 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/18 19:29:28 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*curr;
	t_list	*next;

	if (f == 0 || del == 0)
		return (NULL);
	if (lst == NULL || (head = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	curr = head;
	next = lst->next;
	while (next)
	{
		if ((curr->next = ft_lstnew(f(next->content))) == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		curr = curr->next;
		next = next->next;
	}
	return (head);
}
