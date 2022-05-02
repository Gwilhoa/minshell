/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:57:02 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/02 14:08:13 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief translate arguments for executing path
 * 
 * @param args (a refaire avec la structure)
 * @param env environment of shell
 * @return int result to executing path
 */
int	cmd_bash(char **args, char *env[])
{
	char	*newargv[3];
	int		ret;

	newargv[0] = args[0];
	newargv[1] = args[1];
	newargv[2] = args[2];
	g_error = INEXECVE;
	ret = path_execute_process(args[0], newargv, env);
	return (ret);
}

/**
 * @brief trying path execute
 * 
 * @param cmd cmd to testing
 * @param args arguments for executing
 * @param env environment of shell
 * @return int return 1 if success executimg command in path
 */
int	path_execute_process(char *cmd, char *args[], char *env[])
{
	char	**path;
	int		size;
	int		i;
	int		pid;
	int		status;

	i = -1;
	path = ft_split(getenv("PATH"), ':');
	size = ft_matrixlen((const char **)path);
	while (++i < size)
	{
		if (path_execute(path[i], cmd, args, env) != 0)
			return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, args, env) != -1)
			exit(0);
		exit(1);
	}
	waitpid(pid, &status, 0);
	if (status == 1)
		return (1);
	return (0);
}

/**
 * @brief execute with path the command
 * 
 * @param path the path test for the command
 * @param cmd the command's label
 * @param args the arguments to testing
 * @param env environnment to shell
 * @return int return 1 if success executing in one patg
 */
int	path_execute(char *path, char *cmd, char *args[], char *env[])
{
	int		status;
	char	*format;
	char	*temp;
	int		pid;

	status = -1;
	pid = fork();
	if (pid == 0)
	{
		temp = ft_strjoin(path, "/");
		format = ft_strjoin(temp, cmd);
		free(temp);
		if (execve(format, args, env) != -1)
			exit(0);
		exit(1);
	}
	waitpid(pid, &status, 0);
	if (status == 0)
		return (1);
	return (0);
}
