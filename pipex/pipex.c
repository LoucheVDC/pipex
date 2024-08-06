/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpouille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:24:09 by lpouille          #+#    #+#             */
/*   Updated: 2023/08/31 15:24:10 by lpouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	enfant_process(int fd1, char *cmd1, int *fd, char **envp)
{
	char	**cmd;
	char	**chemin;
	char	*chemin2;
	int		b;

	cmd = ft_split(cmd1, " ");
	close(fd[0]);
	dup2(fd1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	chemin = ft_split(envp[find_path(envp)], ":=");
	b = 1;
	while (chemin[b] != NULL)
	{
		chemin2 = ft_strjoin("/", cmd[0]);
		chemin2 = ft_strjoin(chemin[b], chemin2);
		if (execve(chemin2, ft_split(cmd1, " "), NULL) != -1)
		{
			free(chemin);
			free(chemin2);
			break ;
		}
		b++;
	}
	exit(EXIT_FAILURE);
}

void	parent_process(int fd2, char *cmd2, int *fd, char **envp)
{
	char	**cmd;
	char	**chemin;
	char	*chemin2;
	int		b;

	cmd = ft_split(cmd2, " ");
	wait(NULL);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(fd[1]);
	chemin = ft_split(envp[find_path(envp)], ":=");
	b = 1;
	while (chemin[b] != NULL)
	{
		chemin2 = ft_strjoin("/", cmd[0]);
		chemin2 = ft_strjoin(chemin[b], chemin2);
		if (execve(chemin2, cmd, NULL) != -1)
		{
			free(chemin);
			free(chemin2);
			break ;
		}
		b++;
	}
	exit(EXIT_FAILURE);
}

void	pipex(int *fd1, char *cmd1, char *cmd2, char **envp)
{
	int		fd[2];
	pid_t	parent;

	pipe(fd);
	parent = fork();
	if (parent == -1)
		return (perror("Fork :"));
	if (parent == 0)
		enfant_process(fd1[0], cmd1, fd, envp);
	else
		parent_process(fd1[1], cmd2, fd, envp);
}

int	main(int ac, char **ag, char **envp)
{
	int	fd1[3];

	if (ac != 5)
	{
		perror("Invalid arguments");
		return (-1);
	}
	fd1[0] = open(ag[1], O_RDWR, 0777);
	fd1[1] = open(ag[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	fd1[2] = 0;
	if (fd1[0] < 0 || fd1[1] < 0)
	{
		perror("Invalid fd");
		return (-1);
	}
	pipex(fd1, ag[2], ag[3], envp);
	return (0);
}
