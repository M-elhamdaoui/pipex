/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:45:49 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/12/25 15:07:32 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	while (*(haystack + i) && i < (size_t)ft_strlen((char *)haystack))
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j)
			&& i + j < len && *(needle + j))
			j++;
		if (j == (size_t)ft_strlen(needle))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
