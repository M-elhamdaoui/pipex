/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:37:47 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/01/02 17:22:13 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**splitting(char *cmd)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			c = '\'';
			break ;
		}
		else if (cmd[i] == '"')
		{
			c = '"';
			break ;
		}
		i++;
	}
	return (ft_split(cmd, c));
}
