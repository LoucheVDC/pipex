/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpouille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:29:08 by lpouille          #+#    #+#             */
/*   Updated: 2023/09/13 14:29:10 by lpouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	pipex(int *fd1, char *cmd1, char *cmd2, char **envp);
void	parent_process(int fd2, char *cmd2, int *fd, char **envp);
void	enfant_process(int fd1, char *cmd1, int *fd, char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char *str, char *charset);
int		find_path(char **env);

#endif
