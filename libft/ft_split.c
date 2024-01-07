/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:37:46 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/07 17:29:10 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else
		{
			i++;
		}
	}
	return (count);
}

void	ft_free(char **res, int i)
{
	while (i >= 0)
		free(res[i--]);
	free(res);
}

static void	fill(const char *s, char c, char **res)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			res[i++] = ft_substr(s, 0, len);
			if (!res[i - 1])
			{
				ft_free(res, i - 1);
				return ;
			}
			s += len;
		}
	}
	res[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	fill(s, c, res);
	return (res);
}
