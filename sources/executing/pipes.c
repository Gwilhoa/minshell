/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:22 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/01 10:39:15 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipes(t_minishell *shell)
{
	int			fd[2];
	t_process	*process;

	process = shell->process;
	while (process->next != NULL)
	{
		if (pipe(fd) < 0)
			perror("no");
		process->outfd = fd[1];
		process->next->infd = fd[0];
		process = process->next;
	}
	ft_setfilefd(shell);
}

void	ft_setfilefd(t_minishell *mini)
{
	t_process	*process;

	process = mini->process;
	while (process != NULL)
	{
		if (process->outfile != NULL)
		{
			if (process->outfd != 0)
				close(process->outfd);
			if (process->code == 1)
				process->outfd = open(process->outfile, O_WRONLY | O_TRUNC);
			else
				process->outfd = open(process->outfile, O_WRONLY | O_APPEND);
		}
		if (process->infile != NULL)
		{
			if (process->infd != 0)
				close(process->infd);
			process->infd = open(process->infile, O_RDONLY);
		}
		process = process->next;
	}
}
