/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:57:02 by gchatain          #+#    #+#             */
/*   Updated: 2022/09/01 11:37:43 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	searching_cmd(t_minishell *mini, t_process *process)
{
	if (ft_strcmp(process->cmd, "cd") == 0)
		ft_cd(process, mini);
	else if (ft_strcmp(process->cmd, "env") == 0)
		ft_env(mini->env);
	else if (ft_strcmp(process->cmd, "echo") == 0)
		ft_echo(process);
	else if (ft_strcmp(process->cmd, "export") == 0)
	{
		ft_export(process, mini);
		exit(0);
	}
	else if (ft_strcmp(process->cmd, "unset") == 0)
	{
		ft_unset(process, mini);
		exit(0);
	}
	else if (ft_strcmp(process->cmd, "pwd") == 0)
		ft_pwd(mini->env);
	else if (ft_strcmp(process->cmd, "exit") == 0)
		ft_exit(mini, process);
	else
		ft_bash(mini, process);
}

void	ft_bash(t_minishell *mini, t_process *process)
{
	char	*path;

	if (access(process->cmd, F_OK) == 0 && access(process->cmd, X_OK) == 0)
		ft_execute(process->cmd, process, mini, 1);
	path = ft_getenv("PATH", mini->env);
	if (path)
		ft_searching_path(mini, process, path);
	dup2(mini->default_outfd, 1);
	ft_printf("%s: command not found\n", process->cmd);
	exit(CMDNOTFOUND);
}

void	ft_searching_path(t_minishell *mini, t_process *process, char *path)
{
	int		i;
	int		f;
	char	**splited_path;
	char	*tmp;

	i = 0;
	f = 0;
	splited_path = ft_split(path, ':');
	if (process->cmd[0] != '/')
	{
		while (splited_path[i] != 0)
		{
			tmp = ft_strjoin(splited_path[i], "/");
			tmp = ft_strjoin_free_first(tmp, process->cmd);
			if (access(tmp, F_OK) == 0)
				ft_execute(splited_path[i], process, mini, 0);
			free(tmp);
			i++;
		}
	}
	else
		f = 1;
	ft_free_matrix(splited_path);
	free(splited_path);
	ft_execute(getcwd(NULL, 0), process, mini, f);
}

void static	ft_printerror(char *cmd)
{
	ft_putstr_fd("minshell >>> ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(" command not found\n", 2);
}

void	ft_execute(char *path, t_process *process, t_minishell *mini, \
		int isabsolute)
{
	char	*temp;
	char	*path_cmd;
	char	**args;
	int		i;

	i = -1;
	if (isabsolute == 0)
	{
		temp = ft_strjoin(path, "/");
		free(path);
		path_cmd = ft_strjoin_free_first(temp, process->cmd);
	}
	else
		path_cmd = process->cmd;
	args = ft_split_bash(process->args);
	while (args && args[++i])
		ft_delquotes(&args[i]);
	ft_push_matrix(&args, process->cmd);
	if (isabsolute == 1 && access(path_cmd, X_OK) != 0)
		absolute_failed(process->cmd);
	if (execve(path_cmd, args, mini->env) < 0)
	{
		ft_printerror(process->cmd);
		exit(CMDNOTFOUND);
	}
}
