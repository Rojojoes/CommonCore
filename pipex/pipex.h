/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:36:38 by rogde-so          #+#    #+#             */
/*   Updated: 2025/08/30 20:08:36 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_parameters
{
	char	***cmds;
	char	**paths;
	char	**envp;
	int		**pipes;
	int		pipecount;
	int		filefd[2];
	int		argc;
}	t_parameters;

int		file_checker(char *file1, char *file2, int *filefd);
char	***cmd_matrix(int ac, char *av[]);
char	**find_envp_path(char **envp);
int		parentwait(void);

void	freearray(char **array);
void	freematrix(char ***matrix);
void	freeintarray(int **array, int pipecount);
void	free_everything(t_parameters *data);

int		count_strings(char *s, int i, int count);
char	*extract_string(char *s, int *ptr_i, int i);
char	**split_cmd(char *s);

void	close_all_pipes(int	**pipes, int pipecount);
int		**pipealloc(int pipecount);
int		execute_cmds(t_parameters *data, char **envp);
char	*find_cmd_path(char *cmd, char **paths, t_parameters *data);
void	execute_child(t_parameters *data, int i);

#endif