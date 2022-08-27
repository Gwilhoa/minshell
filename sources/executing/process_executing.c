/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_executing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:15:30 by gchatain          #+#    #+#             */
/*   Updated: 2022/08/27 10:53:46 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_forks(t_minishell *mini, t_process *process)
{
	if (ft_strlen(process->cmd) == 0)
		ft_exit(mini, process);
	g_error = 0;
	ft_cleanfork(process->outfd, process->infd, mini);
	ft_changedup(mini, process);
	searching_cmd(mini, process);
	close(mini->default_infd);
	close(mini->default_outfd);
	ft_exit(mini, process);
}

t_process	*process_executing(t_minishell *mini, t_process *process)
{
	int	pid;

	if (ft_strcmp(process->cmd, "") == 0)
	{
		g_error = 127;
		ft_putstr_fd("minshell >>> : command not found\n", 2);
		return (NULL);
	}
	pid = fork();
	process->pid = pid;
	if (pid < 0)
	{
		perror("pid");
		exit(1);
	}
	else if (pid == 0)
		ft_forks(mini, process);
	else
		signal(SIGINT, sigfork);
	close(process->outfd);
	close(process->infd);
	dup2(mini->default_outfd, 1);
	dup2(mini->default_infd, 0);
	return (process->next);
}

void static	exec2(t_process *process, t_minishell *mini)
{
	int			status;

	g_error = INEXECVE;
	while (process != NULL && process->cmd != NULL)
		process = process_executing(mini, process);
	process = mini->process;
	while (process != NULL)
	{
		waitpid(process->pid, &status, 0);
		if (g_error != SIGC && g_error != 131 && g_error != 127)
			g_error = WEXITSTATUS(status);
		process = process->next;
	}
	if (g_error == 131)
		ft_printf("Quit: 3\n");
	signal(SIGINT, get_signal);
}

void	inexec(t_minishell *mini)
{
	t_process	*process;

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
		exec2(process, mini);
}

void	absolute_failed(char *str)
{
	dup2(2, 1);
	ft_printf("minshell >>> %s : no such file or directory\n", str);
	exit(126);
}
