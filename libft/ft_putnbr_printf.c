/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:29:40 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/12/23 10:27:16 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putnbr_printf(long n, int *i, int base, int cap)
{
	long	nb;
	char	c;

	if (!i)
		return ;
	if (cap == 3)
	{
		ft_putstr_printf("0x", i);
		cap = 0;
	}
	nb = n;
	if (nb < 0)
	{
		c = '-';
		ft_putchar_print(c, i);
		nb = nb * (-1);
	}
	if (nb >= base)
		ft_putnbr_printf(nb / base, i, base, cap);
	c = get_hex(nb % base, cap);
	ft_putchar_print(c, i);
}
