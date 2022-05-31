/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:10:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/31 13:57:09 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	mini;
	char		*pwd;

	(void) argc;
	(void) argv;
	signal(SIGINT, get_signal);
	signal(SIGQUIT, get_signal);
	g_error = 0;
	mini.default_outfd = dup(1);
	mini.default_infd = dup(0);
	if (ft_matrixlen(envp) == 0)
	{
		mini.env = malloc(sizeof(char *));
		mini.env[0] = 0;
		pwd = getcwd(NULL, 0);
		ft_addenv(&mini, "SHLVL=1");
		ft_addenv(&mini, ft_strjoin("PWD=", pwd));
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
	int			status;

	while (1)
	{
		mini->process = NULL;
		line = readline("minshell >> ");
		if (line == NULL)
			exit(0);
		if (line[0] != 0)
		{
			add_history(line);
			ft_check_string(&line, mini->env);
			mini->str = line;
			ft_parsing(mini);
			create_pipes(mini);
			process = mini->process;
			g_error = INEXECVE;
			while (process != NULL && process->cmd != NULL)
				process = process_executing(mini, process);
			while (wait(&status) > 0)
				g_error = status % 255;
		}
	}
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
