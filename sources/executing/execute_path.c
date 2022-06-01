/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:57:02 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/01 13:09:21 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_changedup(t_minishell *mini, t_process *process)
{
	if (process->infd != 0)
	{
		dup2(process->infd, 0);
		close(process->infd);
	}
	else
		dup2(mini->default_infd, 0);
	if (process->outfd != 0)
	{
		dup2(process->outfd, 1);
	}
}

void	searching_cmd(t_minishell *mini, t_process *process)
{
	if (ft_strcmp(process->cmd, "cd") == 0)
		ft_cd(process, mini);
	else if (ft_strcmp(process->cmd, "env") == 0)
		ft_env(mini->env);
	else if (ft_strcmp(process->cmd, "echo") == 0)
		ft_echo(process, mini);
	else if (ft_strcmp(process->cmd, "export") == 0)
		ft_export(process, mini);
	else if (ft_strcmp(process->cmd, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(process->cmd, "unset") == 0)
		ft_unset(process, mini);
	else
		ft_bash(mini, process);
}

void	ft_bash(t_minishell *mini, t_process *process)
{
	char	*path;

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
	char	**splited_path;
	char	*tmp;

	i = 0;
	splited_path = ft_split(path, ':');
	while (splited_path[i] != 0)
	{
		tmp = ft_strjoin(splited_path[i], "/");
		tmp = ft_strjoin(tmp, process->cmd);
		if (access(tmp, F_OK) == 0)
			ft_execute(splited_path[i], process, mini);
		i++;
	}
	if (access(process->cmd, F_OK) == 0)
		ft_execute(getcwd(NULL, 0), process, mini);
}

void	ft_execute(char *path, t_process *process, t_minishell *mini)
{
	char	*temp;
	char	*path_cmd;
	char	*args[3];

	temp = ft_strjoin(path, "/");
	path_cmd = ft_strjoin(temp, process->cmd);
	args[0] = process->cmd;
	args[1] = process->args;
	args[2] = 0;
	if (execve(path_cmd, args, mini->env) < 0)
	{
		perror("execve");
		exit(127);
	}
	return ;
}
