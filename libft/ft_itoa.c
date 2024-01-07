/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:14:51 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/07 16:08:06 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	i;
	long	nb;

	i = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static int	pw(int a)
{
	int	size;

	size = 1;
	if (a == 0)
		return (size);
	while (a > 0)
	{
		size *= 10;
		a--;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;
	size_t	i;
	long	nb;

	i = 0;
	nb = n;
	len = get_len(nb);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb = nb * (-1);
		i = 1;
		len--;
	}
	while (len-- > 0)
	{
		res[i++] = ((nb / pw(len)) % 10) + 48;
	}
	res[i] = '\0';
	return (res);
}
