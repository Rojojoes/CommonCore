/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:53:49 by rogde-so          #+#    #+#             */
/*   Updated: 2025/08/30 20:22:25 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_cmd(char *s)
{
	int		cmdstrings;
	int		i;
	int		pos;
	char	**cmd;

	i = 0;
	pos = 0;
	cmdstrings = count_strings(s, 0, 0);
	cmd = malloc((cmdstrings + 1) * sizeof(char *));
	if (!cmd)
		return (cmd = NULL, NULL);
	while (i < cmdstrings)
	{
		cmd[i] = extract_string(s, &pos, 0);
		if (!cmd[i])
		{
			while (i-- > 0)
				free(cmd[i]);
			free(cmd);
			return (NULL);
		}
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

int	**pipealloc(int pipecount)
{
	int	i;
	int	**pipes;

	if (pipecount > 255 || pipecount <= 0)
		return (perror(" Too many cmds or pipecount <= 0"), NULL);
	i = 0;
	pipes = malloc(sizeof(*pipes) * pipecount);
	if (!pipes)
		return (perror(" Pipe malloc fail "), NULL);
	while (i < pipecount)
	{
		pipes[i] = malloc(sizeof(*pipes[i]) * 2);
		if (!pipes[i] || pipe(pipes[i]) < 0)
		{
			while (--i >= 0)
			{
				close(pipes[i][0]);
				close(pipes[i][1]);
				free(pipes[i]);
			}
			return (perror(" Piping fail "), NULL);
		}
		i++;
	}
	return (pipes);
}

char	*find_cmd_path(char *cmd, char **paths, t_parameters *data)
{
	int		i;
	char	*path_no_cmd;
	char	*path_with_cmd;

	i = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
	}
	while (paths[i])
	{
		path_no_cmd = ft_strjoin(paths[i], "/");
		if (!path_no_cmd)
			return (perror("path strjoin fail"), NULL);
		path_with_cmd = ft_strjoin(path_no_cmd, cmd);
		free(path_no_cmd);
		if (!path_with_cmd)
			return (perror("path strjoin fail"), NULL);
		if (access(path_with_cmd, X_OK) == 0)
			return (path_with_cmd);
		free(path_with_cmd);
		i++;
	}
	return (free_everything(data), perror("No path for cmd found"), NULL);
}

void	execute_child(t_parameters *data, int i)
{
	char	*realpath;

	if (i == 0)
		dup2(data->filefd[0], STDIN_FILENO);
	else
		dup2(data->pipes[i - 1][0], STDIN_FILENO);
	if (i == data->argc - 1)
		dup2(data->filefd[1], STDOUT_FILENO);
	else
		dup2(data->pipes[i][1], STDOUT_FILENO);
	close_all_pipes(data->pipes, data->pipecount);
	close(data->filefd[0]);
	close(data->filefd[1]);
	realpath = find_cmd_path(data->cmds[i][0], data->paths, data);
	if (!realpath)
		exit(EXIT_FAILURE);
	execve(realpath, data->cmds[i], data->envp);
	perror(" Execve fail ");
	free_everything(data);
	exit(EXIT_FAILURE);
}

int	execute_cmds(t_parameters *data, char **envp)
{
	int		i;
	pid_t	pid;

	i = 0;
	data->envp = envp;
	while (i < data->argc)
	{
		pid = fork();
		if (pid < 0)
			return (perror(" Fork fail "), 1);
		if (pid == 0)
			execute_child(data, i);
		if (i > 0)
			close(data->pipes[i - 1][0]);
		if (i < data->argc - 1)
			close(data->pipes[i][1]);
		i++;
	}
	close(data->filefd[0]);
	close(data->filefd[1]);
	close_all_pipes(data->pipes, data->pipecount);
	return (parentwait());
}
