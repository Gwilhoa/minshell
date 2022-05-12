/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:10:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/12 10:06:32 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	mini;

	(void) argc;
	(void) argv;
	mini.process = NULL;
	mini.default_fd = dup(1);
	mini.env = ft_matrix_dup(envp);
	incr_shlvl(&mini);
	signal(SIGQUIT, get_signal);
	signal(SIGKILL, get_signal);
	loop(&mini);
	return (0);
}

void	executing(t_minishell *mini, t_process *process)
{
	if (process->next == NULL)
	{
		if (process->outfile == NULL)
			interpreting(mini, process);
		else
		{
			if (process->code == 1)
				process->outfd = open(process->outfile, O_WRONLY | O_CREAT, 0777);
			else
				process->outfd = open(process->outfile, O_APPEND | O_WRONLY | O_CREAT, 0777);
			if (process->outfd != -1)
			{
				dup2(process->outfd, 1);
				interpreting(mini, process);
				dup2(mini->default_fd, 1);
				close(process->outfd);
			}
			else
				perror("minshell >>>");
		}
	}
}

int	loop(t_minishell *mini)
{
	char		*line;
	t_process	*process;

	while (1)
	{
		signal(SIGINT, get_signal);
		signal(SIGQUIT, get_signal);
		mini->process = NULL;
		g_error = 0;
		line = readline("minshell >> ");
		if (!line)
			break ;
		if (line[0] != 0)
		{
			add_history(line);
			mini->str = line;
			if (ft_parsing(mini) == -1)
			{
				ft_printf("minshell >>> parsing error");
				return(0);
			}
			return (0);//---
			process = mini->process;
			create_pipes(mini);
			executing(mini, process);
		}
	}
	ft_exit(0);
	return (1);
}
