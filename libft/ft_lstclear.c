/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 01:46:20 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/07 17:58:48 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (lst && *lst)
	{
		while ((*lst)->next)
		{
			ptr = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			(*lst) = ptr;
		}
		del((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
}
