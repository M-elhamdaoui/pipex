/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 01:50:41 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/01/03 18:53:48 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_file_normal(int ac, int *pipefd, char **av)
{
	int	fd1;

	fd1 = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	error_handle(fd1, av[ac -1]);
	error_handle(dup2(fd1, pipefd[1]), "dup2");
	error_handle(close(fd1), "close");
}

void	create_file_here_doc(int ac, int *pipefd, char **av)
{
	int	fd1;

	fd1 = open(av[ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	error_handle(fd1, av[ac - 1]);
	error_handle(dup2(fd1, pipefd[1]), "dup2");
	error_handle(close(fd1), "close");
}

int	create_the_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	error_handle(fd, file);
	return (fd);
}

int	is_here_doc(char *str)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "here_doc") == 0)
		i = 1;
	return (i);
}

void	do_extra(int *pipefd, int fd)
{
	if (read(0, NULL, 0) != -1)
	{
		error_handle(dup2(pipefd[0], fd), "dup2");
		error_handle(close(pipefd[0]), "close");
		error_handle(close(pipefd[1]), "close");
	}
}
