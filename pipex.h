/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:51:35 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/01/03 17:25:30 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "fcntl.h"
# include <stdio.h>
# include <errno.h> 

char	**extract_path_from_env(char **env);
char	*get_the_correct_path(char **env, char *cmd);
void	child_one(char **av, char **env, int pipefd[2]);
void	child_two(char **av, char **env, int pipefd[2]);
void	error_handle(int i, char *command);
void	error_command_not_found(char *command);
char	**splitting(char *cmd);

#endif