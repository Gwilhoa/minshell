/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:10:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/30 17:26:33 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	mini;
	char	*pwd;

	(void) argc;
	(void) argv;
	g_error = 0;
	mini.process = NULL;
	mini.default_outfd = dup(1);
	mini.default_infd = dup(0);
	if (ft_matrixlen(envp) == 0)
	{
		mini.env = malloc(sizeof(char *));
		mini.env[0] = 0;
		pwd = getcwd(NULL, 0);
		ft_addenv(&mini, "SHLVL=1");
		ft_addenv(&mini, ft_strjoin("PWD=",pwd));
	}
	else
	{
		mini.env = ft_matrix_dup(envp);
		incr_shlvl(&mini);
	}
	loop(&mini);
	return (0);
}

int	loop(t_minishell *mini)
{
	char		*line;
	t_process	*process;
	int pid;

	while (1)
	{
		signal(SIGINT, get_signal);
		signal(SIGQUIT, get_signal);
		mini->process = NULL;
		line = readline("minshell >> ");
		if (!line)
			break ;
		if (line[0] != 0)
		{
			add_history(line);
			ft_check_string(&line, mini->env);
			mini->str = line;
			if (ft_parsing(mini) == -1)
				continue ;
			else
			{
				create_pipes(mini);
				process = mini->process;
				while (process != NULL && process->cmd != NULL)
				{
					pid = fork();
					if (pid < 0)
						perror("pid");
					else if (pid == 0)
					{
						ft_cleanfork(process->outfd, process->infd, mini);
						ft_changedup(mini, process);
						if (process->outfd != 0)
							close(process->outfd);
						exit(0);
					}
					close(process->outfd);
					close(process->infd);
					dup2(mini->default_outfd, 1);
					dup2(mini->default_infd, 0);
					g_error = 0;
					process = process->next;
				}
				while (wait(NULL) > 0)
					;
			}
		}
	}
	exit(0);
}

void	incr_shlvl(t_minishell *mini)
{
	char		*temp;
	char		*ret;

	temp = ft_getenv("SHLVL", mini->env);
	ret = ft_itoa(ft_atoi(temp) + 1);
	ft_change_env("SHLVL", ret, mini);
	free(ret);
}

void	ft_cleanfork(int outfd, int infd, t_minishell *mini)
{
	t_process	*process;

	process = mini->process;
	while (process != NULL)
	{
		if (process->outfd != outfd)
			close(process->outfd);
		if (process->infd != infd)
			close(process->infd);
		process = process->next;
	}
}
