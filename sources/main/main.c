/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:10:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/22 17:15:20 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_empty_env(t_minishell *mini)
{
	char	*pwd;

	mini->env = malloc(sizeof(char *));
	mini->env[0] = 0;
	pwd = getcwd(NULL, 0);
	ft_addenv(mini, "SHLVL=1");
	ft_addenv(mini, ft_strjoin("PWD=", pwd));
	free(pwd);
}

void	init_env(char **envp, t_minishell *mini)
{
	int		i;

	i = -1;
	if (ft_matrix_size((const char **)envp) == 0)
		init_empty_env(mini);
	else
	{
		mini->env = ft_matrix_dup(envp);
		while (mini->env[++i] != 0)
		{
			if (ft_strncmp(mini->env[i], "OLDPWD", 6) == 0)
			{
				free(mini->env[i]);
				mini->env[i] = ft_strdup("OLDPWD");
			}
		}
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
	char		*temp;

	while (1)
	{
		line = readline("minshell >> ");
		if (line == NULL)
			ft_exit(mini, NULL);
		if (line[0] != 0)
		{
			add_history(line);
			if (line != NULL)
			{
				temp = ft_strdup(line);
				free(line);
				line = temp;
				ft_check_dollar(&line, mini->env, 0, 1);
				g_error = 0;
				if (ft_parsing(mini, line) == 0 && g_error == 0)
					inexec(mini);
			}
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
	free(temp);
}
