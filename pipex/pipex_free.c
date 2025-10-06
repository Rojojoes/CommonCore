/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:07:50 by rogde-so          #+#    #+#             */
/*   Updated: 2025/09/05 18:20:46 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freematrix(char ***matrix)
{
	int	i;
	int	j;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			free(matrix[i][j]);
			matrix[i][j] = NULL;
			j++;
		}
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void	freearray(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	freeintarray(int **array, int pipecount)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (i < pipecount)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	close_all_pipes(int	**pipes, int pipecount)
{
	int	i;

	i = 0;
	while (i < pipecount)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	free_everything(t_parameters *data)
{
	close(data->filefd[0]);
	close(data->filefd[1]);
	if (data->cmds)
		freematrix(data->cmds);
	if (data->paths)
		freearray(data->paths);
	if (data->pipes)
		freeintarray(data->pipes, data->pipecount);
}
