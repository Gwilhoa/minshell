/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_executing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:15:30 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/13 15:13:07 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_forks(t_minishell *mini, t_process *process)
{
	if (ft_strlen(process->cmd) == 0)
		exit(0);
	g_error = 0;
	ft_cleanfork(process->outfd, process->infd, mini);
	ft_changedup(mini, process);
	searching_cmd(mini, process);
	exit(0);
}

t_process	*process_executing(t_minishell *mini, t_process *process)
{
	int	pid;

	pid = fork();
	process->pid = pid;
	if (pid < 0)
		perror("pid");
	else if (pid == 0)
		ft_forks(mini, process);
	close(process->outfd);
	close(process->infd);
	dup2(mini->default_outfd, 1);
	dup2(mini->default_infd, 0);
	return (process->next);
}

void	inexec(t_minishell *mini)
{
	t_process	*process;
	int			status;

	create_pipes(mini);
	process = mini->process;
	if (ft_strcmp(process->cmd, "cd") == 0 && process->next == NULL)
		ft_cd(process, mini);
	else if (ft_strcmp(process->cmd, "export") == 0 && process->next == NULL \
		&& process->args != NULL)
		ft_export(process, mini);
	else if (ft_strcmp(process->cmd, "unset") == 0 && process->next == NULL \
		&& process->args != NULL)
		ft_unset(process, mini);
	else if (ft_strcmp(process->cmd, "exit") == 0 && process->next == NULL)
		ft_exit(mini, process);
	else
	{
		g_error = INEXECVE;
		while (process != NULL && process->cmd != NULL)
			process = process_executing(mini, process);
		process = mini->process;
		while (process != NULL)
		{
			waitpid(process->pid, &status, 0);
			g_error = WEXITSTATUS(status);
			process = process->next;
		}
	}
}

void	absolute_failed(char *str)
{
	dup2(2, 1);
	ft_printf("minshell >>> %s : is a directory\n", str);
	exit(126);
}
