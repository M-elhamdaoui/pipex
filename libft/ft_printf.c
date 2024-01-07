/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:07:29 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/12/23 10:27:05 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	control(const char *s, va_list d, int *i)
{
	if (*(s) == 'd' || *(s) == 'i')
		ft_putnbr_printf(va_arg(d, int), i, 10, 0);
	else if (*(s) == 's')
		ft_putstr_printf(va_arg(d, char *), i);
	else if (*(s) == 'c')
		ft_putchar_print(va_arg(d, int), i);
	else if (*(s) == '%')
		ft_putchar_print(*s, i);
	else if (*(s) == 'u')
		ft_putnbr_printf(va_arg(d, unsigned int), i, 10, 0);
	else if (*(s) == 'x')
		ft_putnbr_printf(va_arg(d, unsigned int), i, 16, 0);
	else if (*(s) == 'X')
		ft_putnbr_printf(va_arg(d, unsigned int), i, 16, 1);
	else if (*(s) == 'p')
		ft_print_pointer_adress(va_arg(d, unsigned long), i, 0);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while (*s != 000)
	{
		if (*s == '%')
		{
			s++;
			if (control(s, args, &i))
				s++;
			continue ;
		}
		else
			ft_putchar_print(*s, &i);
		s++;
	}
	va_end(args);
	return (i);
}
