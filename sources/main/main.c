/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:10:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/18 19:38:24 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char **envp, t_minishell *mini)
{
	char	*pwd;

	if (ft_matrix_size((const char **)envp) == 0)
	{
		mini->env = malloc(sizeof(char *));
		mini->env[0] = 0;
		pwd = getcwd(NULL, 0);
		ft_addenv(mini, "SHLVL=1");
		ft_addenv(mini, ft_strjoin("PWD=", pwd));
	}
	else
	{
		mini->env = ft_matrix_dup(envp);
		incr_shlvl(mini);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	mini;

	(void) argc;
	(void) argv;
	signal(SIGINT, get_signal);
	signal(SIGQUIT, get_signal);
	g_error = 0;
	mini.default_outfd = dup(1);
	mini.default_infd = dup(0);
	init_env(envp, &mini);
	mini.process = NULL;
	loop(&mini);
	return (0);
}

int	loop(t_minishell *mini)
{
	char		*line;
	t_process	*tmp;

	while (1)
	{
		mini->process = NULL;//si mini->process != null alors free tout les process
		line = readline("minshell >> ");
		if (line == NULL)
			ft_exit(mini, NULL);
		if (line[0] != 0)
		{
			add_history(line);
			if (line != NULL)
			{
				mini->str = line;
				ft_check_dollar(&mini->str, mini->env, 0, 1);
				g_error = 0;
				if (ft_parsing(mini) != 0)
				{
					g_error = ERRO_SYNTAXE;
					printf("syntax error\n");
				}
				if (g_error == 0)
					inexec(mini);
			}
		}
		free(line);
		while (mini->process)
		{
			tmp = mini->process->next;
			ft_free_process(mini->process);
			free(mini->process);
			mini->process = tmp;
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
