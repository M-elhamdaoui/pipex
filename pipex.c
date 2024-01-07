/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:51:22 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/01/02 17:25:22 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(char **av, char **env, int pipefd[2])
{
	int		fd;
	char	**cmd;
	char	*path;
	char	*command;

	error_handle(dup2(pipefd[1], STDOUT_FILENO), "dup2");
	fd = open(av[1], O_RDONLY);
	error_handle(fd, av[1]);
	error_handle(dup2(fd, STDIN_FILENO), "dup2");
	error_handle(close(fd), "close");
	error_handle(close(pipefd[1]), "close");
	error_handle(close(pipefd[0]), "close");
	cmd = splitting(av[2]);
	command = ft_strtrim(cmd[0], " ");
	path = get_the_correct_path(env, command);
	error_handle(execve(ft_strjoin(path, command), cmd, env), cmd[0]);
}

void	child_two(char **av, char **env, int pipefd[2])
{
	int		fd;
	char	**cmd;
	char	*path;
	char	*command;

	error_handle(dup2(pipefd[0], STDIN_FILENO), "dup2");
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	error_handle(fd, av[4]);
	error_handle(dup2(fd, STDOUT_FILENO), "dup2");
	error_handle(close(fd), "close");
	error_handle(close(pipefd[1]), "close");
	error_handle(close(pipefd[0]), "close");
	cmd = splitting(av[3]);
	command = ft_strtrim(cmd[0], " ");
	path = get_the_correct_path(env, command);
	error_handle(execve(ft_strjoin(path, command), cmd, env), cmd[0]);
}

int	main(int ac, char **av, char **env)
{
	int		pipefd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	status = 0;
	if (ac != 5)
		return (ft_putstr_fd("please type exactly 5 argements", 2), 1);
	error_handle(pipe(pipefd), "pipe");
	pid1 = fork();
	error_handle(pid1, "fork");
	if (pid1 == 0)
		child_one(av, env, pipefd);
	pid2 = fork();
	error_handle(pid2, "fork");
	if (pid2 == 0)
		child_two(av, env, pipefd);
	error_handle(close(pipefd[0]), "close");
	error_handle(close(pipefd[1]), "close");
	error_handle(wait(NULL), "wait");
	error_handle(wait(&status), "wait");
	return (status);
}
