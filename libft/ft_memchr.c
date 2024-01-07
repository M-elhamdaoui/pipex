/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:30:20 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/07 17:24:43 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == ch)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (NULL);
}
