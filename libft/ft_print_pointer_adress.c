/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_adress.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:44 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/12/23 10:26:58 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_pointer_adress(unsigned long n, int *i, int start)
{
	if (start == 0)
		ft_putstr_printf("0x", i);
	if (n >= 16)
		ft_print_pointer_adress(n / 16, i, 1);
	ft_putchar_print(get_hex(n % 16, 0), i);
}
