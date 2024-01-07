/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:34:33 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/07 17:35:00 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*head;

	if (!lst)
		return (NULL);
	l = NULL;
	head = l;
	while (lst)
	{
		l = ft_lstnew(f(lst->content));
		if (!l)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, l);
		lst = lst->next;
	}
	return (head);
}
