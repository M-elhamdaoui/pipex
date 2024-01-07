/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:41:15 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/12/29 12:07:24 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len_get(char *str)
{
	if (*str)
		return (get_len_get(str + 1) + 1);
	return (0);
}

char	*create_buff(void)
{
	char	*buff;
	int		i;

	i = 0;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (i < BUFFER_SIZE)
		buff[i++] = '\0';
	buff[i] = '\0';
	return (buff);
}

char	*ft_strchr_get(char *str, char c)
{
	unsigned char	*st;
	int				i;

	i = 0;
	st = (unsigned char *)str;
	if (!str)
		return (NULL);
	while (*(st + i))
	{
		if (*(st + i) == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

static char	*ft_strjoin_get(char *str, char *buff, int n)
{
	int		s_len;
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	s_len = get_len_get(str);
	new = (char *)malloc(s_len + n + 1);
	if (!new || !buff)
		return (free(str), str = NULL, NULL);
	while (*(str + i))
	{
		new[i] = str[i];
		i++;
	}
	while (j < n)
	{
		new[i + j] = buff[j];
		j++;
	}
	return (free(str), new[i + j] = '\0', new);
}

char	*loading(char *str, int fd)
{
	int		n;
	char	*buff;

	n = 1;
	if (!str)
	{
		str = ft_strdup_get("");
		if (!str)
			return (NULL);
	}
	buff = create_buff();
	if (!buff)
		return (free(str), NULL);
	while (n > 0 && str && !ft_strchr_get(str, '\n'))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
			return (free(str), free(buff), NULL);
		if (n > 0)
			str = ft_strjoin_get(str, buff, n);
	}
	free(buff);
	buff = NULL;
	return (str);
}
