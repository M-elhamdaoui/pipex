/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:20:47 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/12 15:45:07 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_print(char c, int *i)
{
	if (*i != (-1))
	{
		if (write(1, &c, 1) == -1)
		{
			*i = -1;
		}
		else
			*i = *i + 1;
	}
}
