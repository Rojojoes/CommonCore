/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:36:41 by rogde-so          #+#    #+#             */
/*   Updated: 2025/08/30 20:05:26 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parentwait(void)
{
	int	waitstatus;
	int	laststatus;

	laststatus = 0;
	while (wait(&waitstatus) > 0)
	{
		if (WIFEXITED(waitstatus))
			laststatus = WEXITSTATUS(waitstatus);
		else if (WIFSIGNALED(waitstatus))
			laststatus = 128 + WTERMSIG(waitstatus);
	}
	return (laststatus);
}

int	file_checker(char *file1, char *file2, int *filefd)
{
	int	filein;
	int	fileout;

	fileout = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fileout < 0)
		return (perror(" Output file couldn't be opened/created "), 1);
	if (access(file1, R_OK) != 0)
	{
		close(fileout);
		return (perror(" Failed to access input file "), 1);
	}
	filein = open(file1, O_RDONLY);
	if (filein < 0)
	{
		close(fileout);
		return (perror(" Input file couldn't open "), 1);
	}
	filefd[0] = filein;
	filefd[1] = fileout;
	return (0);
}

char	***cmd_matrix(int ac, char *av[])
{
	int		n;
	int		i;
	char	***cmds;

	i = 0;
	n = ac - 3;
	cmds = malloc(sizeof(char **) * (n + 1));
	if (cmds == NULL)
		return (perror(" malloc failed for command matrix "), NULL);
	while (i < n)
	{
		cmds[i] = split_cmd(av[i + 2]);
		if (!cmds[i])
		{
			while (--i >= 0)
				free(cmds[i]);
			free(cmds);
			return (perror(" Split failed "), NULL);
		}
		i++;
	}
	cmds[n] = NULL;
	return (cmds);
}

char	**find_envp_path(char **envp)
{
	int		i;
	int		error;
	char	**paths;

	i = 0;
	error = 0;
	if (envp == NULL)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			error = 1;
			break ;
		}
		i++;
	}
	if (error == 0)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
		return (NULL);
	return (paths);
}

int	main(int ac, char *av[], char *envp[])
{
	t_parameters	data;
	int				status;

	if (!envp[0])
		return (perror(" Environment is null "), 1);
	if (ac < 5)
		return (perror(" Not enough arguments "), 2);
	data.argc = ac - 3;
	if (file_checker(av[1], av[ac - 1], data.filefd) > 0)
		return (perror(" File error "), 3);
	data.paths = find_envp_path(envp);
	if (!data.paths)
		return (close(data.filefd[0]), close(data.filefd[1]), 4);
	data.cmds = cmd_matrix(ac, av);
	if (!data.cmds)
		return (free_everything(&data), 5);
	data.pipecount = data.argc - 1;
	data.pipes = pipealloc(data.pipecount);
	if (!data.pipes)
		return (free_everything(&data), 6);
	status = execute_cmds(&data, envp);
	free_everything(&data);
	return (status);
}
