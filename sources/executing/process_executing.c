/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_executing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:15:30 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/31 13:45:02 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_forks(t_minishell *mini, t_process *process)
{
	g_error = 0;
	ft_cleanfork(process->outfd, process->infd, mini);
	ft_changedup(mini, process);
	if (process->outfd != 0)
		close(process->outfd);
	exit(0);
}

t_process	*process_executing(t_minishell *mini, t_process *process)
{
	int	pid;

	pid = fork();
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
