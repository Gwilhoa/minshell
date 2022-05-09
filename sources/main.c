/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:10:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/09 15:12:43 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	incr_shlvl(t_minishell *mini)
{
	char		*temp;
	char		*ret;

	temp = ft_getenv("SHLVL", mini->env);
	ret = ft_itoa(ft_atoi(temp) + 1);
	free(temp);
	ft_change_env("SHLVL", ret, mini->env);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	mini;

	(void) argc;
	(void) argv;
	mini.process = NULL;
	mini.env = ft_matrix_dup(envp, 0);
	mini.default_fd = dup(1);
	incr_shlvl(&mini);
	signal(SIGQUIT, get_signal);
	signal(SIGKILL, get_signal);
	ft_delenv(&mini, "HOME");
	// ft_disp_matrix(mini.env);
	loop(&mini);
	return (0);
}

int	loop(t_minishell *mini)
{
	char		*line;
	char		**args;
	t_process	*process;
	int			ret;

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
			args = ft_split(line, ' ');//parsing
			if (ft_strlen(args[0]) + 1 > ft_strlen(line))
				new_process(mini, args[0], 0);
			else
				new_process(mini, args[0], line + ft_strlen(args[0]) + 1);//parsing
			process = mini->process;
			while (process != NULL)
			{
				ret = interpreting(mini, process);
				process = process->next;
			}
		}
	}
	ft_exit(0);
	return (1);
}

void	new_process(t_minishell *mini, char *name, char *args)
{
	t_process	*process;
	t_process	*new_process;

	process = mini->process;
	new_process = malloc(sizeof(t_process));
	new_process->cmd = name;
	new_process->args = args;
	new_process->flags = NULL;
	new_process->next = NULL;
	new_process->outfd = 1;
	if (process == NULL)
		mini->process = new_process;
	else
	{
		while (process != NULL)
		{
			process = process->next;
			if (process->next == NULL)
				process->next = new_process;
		}
	}
}
