/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:22 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/16 16:50:52 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipes(t_minishell *shell)
{
	int			fd[2];
	int			i;
	t_process	*process;

	i = 0;
	process = shell->process;
	while (process->next != NULL)
	{
		if (pipe(fd) < 0)
			perror("no");
		process->outfd = fd[1];
		process->next->infd = fd[0];
		i++;
		process = process->next;
	}
	if (process->outfile != NULL)
	{
		if (process->code != 1)
			process->outfd = open(process->outfile, O_WRONLY);
		else
			process->outfd = open(process->outfile, O_WRONLY | O_APPEND);
	}
}
