/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:10:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/13 14:58:09 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	mini;

	(void) argc;
	(void) argv;
	mini.process = NULL;
	mini.default_outfd = dup(1);
	mini.default_infd = dup(0);
	mini.env = ft_matrix_dup(envp);
	incr_shlvl(&mini);
	loop(&mini);
	return (0);
}

void	executing(t_minishell *mini, t_process *process)
{
	if (process->infd != 0)
	{
		dup2(process->infd, 0);
		close(process->infd);
	}
	if (process->outfd != 0)
		dup2(process->outfd, 1);
	interpreting(mini, process);
	dup2(mini->default_outfd, 1);
	if (process->outfd)
		close(process->outfd);
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
				ft_printf("minshell >>> parsing error");
			else
			{
				create_pipes(mini);
				process = mini->process;
				while (process != NULL)
				{
					executing(mini, process);
					dup2(mini->default_outfd, 1);
					dup2(mini->default_infd, 0);
					process = process->next;
				}
			}
		}
	}
	ft_exit(0);
	return (1);
}

void	incr_shlvl(t_minishell *mini)
{
	char		*temp;
	char		*ret;

	temp = ft_getenv("SHLVL", mini->env);
	ret = ft_itoa(ft_atoi(temp) + 1);
	free(temp);
	ft_change_env("SHLVL", ret, mini);
	free(ret);
}
