/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:34:11 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/01/04 15:10:02 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "fcntl.h"
# include <stdio.h>
# include <errno.h> 

char	**extract_path_from_env(char **env);
char	*get_the_correct_path(char **env, char *cmd);
void	error_handle(int i, char *command);
void	error_command_not_found(char *command);
void	child(char *command, int *pipefd, int fd, char **env);
void	handle_childs(int ac, char **av, char **env, pid_t *pids);
void	create_file_normal(int ac, int *pipefd, char **av);
void	create_file_here_doc(int ac, int *pipefd, char **av);
int		create_the_fd(char *file);
int		is_here_doc(char *str);
void	do_extra(int *pipefd, int fd);
void	wait_for_child(int i, pid_t *pids, char **av);
char	**splitting(char *cmd);
int		ft_strcmp(char *s1, char *s2);

#endif