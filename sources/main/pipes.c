/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:22 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/30 15:45:24 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipes(t_minishell *shell)
{
	int			fd[2];
	t_process	*process;

	process = shell->process;
	if (process->infile != NULL)
		process->infd = open(process->infile, O_RDONLY);
	while (process->next != NULL)
	{
		if (pipe(fd) < 0)
			perror("no");
		process->outfd = fd[1];
		process->next->infd = fd[0];
		process = process->next;
	}
	if (process->outfile != NULL)
	{
		if (process->outfd != 0)
			close(process->outfd);
		if (process->code == 1)
			process->outfd = open(process->outfile, O_WRONLY | O_TRUNC);
		else
			process->outfd = open(process->outfile, O_WRONLY | O_APPEND);
	}
	if (process->next != NULL)
	{
		if (process->next->infile != NULL)
		{
			if (process->next->infd != 0)
				close(process->next->infd);
			process->next->infd = open(process->next->infile, O_RDONLY);
		}
	}
}
