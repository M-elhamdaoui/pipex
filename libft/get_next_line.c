/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:33:25 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/12/29 12:08:16 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next(char *str)
{
	char	*next;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (*(str + len) && *(str + len) != '\n')
		len++;
	if (*(str + len) == '\n')
		len++;
	next = (char *)malloc(len + 1);
	if (!next)
		return (NULL);
	while (i < len)
	{
		next[i] = str[i];
		i++;
	}
	return (next[len] = '\0', next);
}

char	*fill(char *str, char *old)
{
	int	j;

	j = 0;
	while (*(old + j))
	{
		str[j] = *(old + j);
		j++;
	}
	return (str[j] = '\0', str);
}

char	*ft_strdup_get(char *s)
{
	char	*new;
	int		len;

	if (!s)
		return (NULL);
	len = get_len_get(s);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	new[len] = '\0';
	return (new);
}

char	*ft_realloc(char *str)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (*(str + i) && *(str + i) != '\n')
		i++;
	if (*(str + i) == '\n')
		i++;
	while (*(str + i + j))
		j++;
	new = (char *)malloc(j + 1);
	if (!new)
		return (free(str), str = NULL, NULL);
	new = fill(new, str + i);
	free(str);
	if (*new == '\0')
		return (free(new), new = NULL, NULL);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*next;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (free(str), str = NULL, NULL);
	if (!ft_strchr_get(str, '\n'))
		str = loading(str, fd);
	next = get_next(str);
	str = ft_realloc(str);
	if (!next || *next == '\0')
		return (free(str), free(next), str = NULL, NULL);
	return (next);
}
