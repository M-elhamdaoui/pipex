/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:30:13 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/01/04 15:11:18 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) && *(s2 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return (s1[i] - s2[i]);
}

static void	load_file(int *fd, char **av)
{
	char	*str;
	char	*test;

	ft_printf("pipe heredoc> ");
	error_handle(close(fd[0]), "close");
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		test = ft_strtrim(str, "\n");
		if (!str || !ft_strcmp(av[2], test))
			break ;
		ft_putstr_fd(str, fd[1]);
		free(str);
		free(test);
		ft_printf("pipe heredoc> ");
	}
	error_handle(close(fd[1]), "close");
	free(str);
	free(test);
	exit(0);
}

void	handle_childs(int ac, char **av, char **env, pid_t *pids)
{
	int	i;
	int	pipefd[2];
	int	fd;

	i = 2;
	fd = 10;
	while (i < ac - 1)
	{
		error_handle(pipe(pipefd), "pipe");
		pids[i - 2] = fork();
		error_handle(pids[i - 2], "fork");
		if (i - 2 == 0 && is_here_doc(av[1]) == 0 && pids[i - 2] == 0)
			fd = create_the_fd(av[1]);
		else if (i == ac - 2 && is_here_doc(av[1]) == 0)
			create_file_normal(ac, pipefd, av);
		else if (i == ac - 2 && is_here_doc(av[1]) == 1)
			create_file_here_doc(ac, pipefd, av);
		if (pids[i - 2] == 0 && ((is_here_doc(av[1]) != 0 && i - 2 != 0)
				|| (is_here_doc(av[1]) == 0)))
			child(av[i], pipefd, fd, env);
		else if (pids[i - 2] == 0 && is_here_doc(av[1]) != 0 && i - 2 == 0)
			load_file(pipefd, av);
		wait_for_child(i, pids, av);
		(do_extra(pipefd, fd), i++);
	}
}

void	child(char *command, int *pipefd, int fd, char **env)
{
	char	**cmd;
	char	*path;
	char	*cmdd;

	error_handle(dup2(fd, STDIN_FILENO), "dup2");
	error_handle(dup2(pipefd[1], STDOUT_FILENO), "dup2");
	error_handle(close(fd), "close");
	error_handle(close(pipefd[0]), "close");
	error_handle(close(pipefd[1]), "close");
	cmd = splitting(command);
	cmdd = ft_strtrim(cmd[0], " ");
	path = get_the_correct_path(env, cmdd);
	error_handle(execve(ft_strjoin(path, cmdd), cmd, env), cmdd);
}

int	main(int ac, char **av, char **env)
{
	pid_t	*pids;
	int		i;
	int		status;

	i = 0;
	status = 0;
	if (ac < 5)
		return (ft_putstr_fd("please type at least 5 argements", 2), 1);
	if (is_here_doc(av[1]) && ac < 6)
		return (ft_putstr_fd("please type at least 6 argements", 2), 1);
	pids = (pid_t *)malloc((ac - 2) * sizeof(pid_t));
	if (!pids)
		return (ft_putstr_fd("Fail allocation", 2), 1);
	while (i < ac - 2)
		pids[i++] = 0;
	handle_childs(ac, av, env, pids);
	i = is_here_doc(av[1]);
	while (i < ac - 2)
	{
		if (pids[i++] != 0)
			error_handle(wait(&status), "wait");
	}
	free(pids);
	return (status);
}
