/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:15:24 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/03 23:08:41 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	i = 0;
	s_len = 0;
	d_len = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (*(dst + d_len) && d_len < dstsize)
		d_len++;
	while (*(src + s_len))
		s_len++;
	while ((d_len + i + 1) < dstsize && *(src + i))
	{
		*(dst + d_len + i) = *(src + i);
		i++;
	}
	if (d_len < dstsize)
		*(dst + d_len + i) = '\0';
	return (d_len + s_len);
}
