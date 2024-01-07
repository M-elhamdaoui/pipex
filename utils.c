/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:51:14 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/01/02 17:21:18 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**extract_path_from_env(char **env)
{
	int		i;
	char	*str;
	char	*res;
	char	**r;

	i = 0;
	if (!env)
	{
		ft_putstr_fd("env is missing ! ", 2);
		exit(1);
	}
	str = NULL;
	while (env[i])
	{
		str = ft_strnstr(env[i], "PATH=", ft_strlen(env[i]));
		if (str)
			break ;
		i++;
	}
	if (!str)
		return (NULL);
	res = ft_strtrim(str, "PATH=");
	r = ft_split(res, ':');
	free(res);
	return (r);
}

char	*get_the_correct_path(char **env, char *cmd)
{
	char	**paths;
	int		i;
	char	*str;

	i = 0;
	if (!env)
		return (NULL);
	paths = extract_path_from_env(env);
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		str = ft_strjoin(paths[i], "/");
		if (access(ft_strjoin(str, cmd), X_OK) == 0)
			return (free(paths), str);
		free(str);
		i++;
	}
	free(paths);
	error_command_not_found(cmd);
	exit(errno);
}

void	error_handle(int i, char *command)
{
	if (i == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(" : ", 2);
		ft_putstr_fd(command, 2);
		ft_putchar_fd('\n', 2);
		exit(errno);
	}
}

void	error_command_not_found(char *command)
{
	ft_putstr_fd("Command not found : ", 2);
	ft_putstr_fd(command, 2);
	ft_putchar_fd('\n', 2);
	exit(errno);
}

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
