/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:57:02 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/16 07:55:42 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	interpreting(t_minishell *mini, t_process *process)
{
	int			ret;

	if (ft_strcmp(process->cmd, "unset") == 0)
		ft_unset(process, mini);
	else if (ft_strcmp(process->cmd, "export") == 0)
		ft_export(process, mini);
	else if (ft_strcmp(process->cmd, "cd") == 0)
		ft_cd(process, mini);
	else if (ft_strcmp(process->cmd, "pwd") == 0)
		ft_pwd(mini);
	else if (ft_strcmp(process->cmd, "env") == 0)
		ft_env(mini->env);
	else if (ft_strcmp(process->cmd, "echo") == 0)
		ft_echo(process, mini);
	else
	{
		ret = cmd_bash(process, mini->env);
		if (g_error == INEXECVE && ret == 0)
		{
			ft_printf("%s\1minshell >>> %s", RED, process->cmd);
			ft_printf(" command not found\n%s\2", WHITE);
		}
		return (1);
	}
	return (0);
}

int	cmd_bash(t_process *process, char **env)
{
	char	*newargv[3];
	int		ret;

	newargv[0] = process->cmd;
	newargv[1] = process->flags;
	newargv[2] = 0;
	g_error = INEXECVE;
	signal(SIGINT, useless_sig);
	signal(SIGQUIT, useless_sig);
	ret = path_execute_process(process->cmd, newargv, env);
	return (ret);
}

int	path_execute_process(char *cmd, char *args[], char *env[])
{
	char	**path;
	char	*line;
	int		size;
	int		i;

	i = -1;
	line = ft_getenv("PATH", env);
	if (line == 0)
		return (0);
	path = ft_split(line, ':');
	size = ft_matrixlen(path);
	while (++i < size)
	{
		line = ft_strjoin(path[i], "/");
		line = ft_strjoin(line, cmd);
		if (access(line, X_OK) == 0)
			return (path_execute(line, args, env));
	}
	line = ft_strjoin(ft_getenv("PWD", env), "/");
	line = ft_strjoin(line, cmd);
	if (access(line, X_OK) == 0)
		return (path_execute(line, args, env));
	return (0);
}

int	path_execute(char *path, char *args[], char *env[])
{
	int		status;
	int		pid;

	status = -1;
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, env) != -1)
			exit(0);
		exit(1);
	}
	waitpid(pid, &status, 0);
	if (status == 0)
		return (1);
	return (3);
}
