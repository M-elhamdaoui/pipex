/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:21:18 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/12/25 15:07:04 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill(char const *s, unsigned int start, size_t len, char *p)
{
	size_t	i;

	i = 0;
	while (*(s + start + i) && i < len)
	{
		*(p + i) = *(s + start + i);
		i++;
	}
	*(p + i) = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len >= (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	fill(s, start, len, p);
	return (p);
}
