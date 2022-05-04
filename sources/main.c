/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:10:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/04 13:40:22 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**env;

	(void) argc;
	(void) argv;
	env = ft_matrix_dup(envp);
	ft_change_env("SHLVL", ft_itoa(ft_atoi(ft_getenv("SHLVL", env)) + 1), env);
	signal(SIGQUIT, get_signal);
	signal(SIGINT, get_signal);
	signal(SIGKILL, get_signal);
	loop(env);
	return (0);
}

int	loop(char *envp[])
{
	STRING	line;
	char	**args;
	int		ret;

	while (1)
	{
		g_error = 0;
		line = readline("minshell >> ");
		if (!line)
			break ;
		if (line[0] != 0)
		{	
			add_history(line);
			args = ft_split(line, ' ');//parsing
			ret = interpreting(args, envp);
		}
	}
	ft_exit(0);
	return (1);
}

/**
 * @brief execute commands with arguments
 * 
 * @param args 
 * @param env 
 * @return int  0 if the commande dosen't found, 1 if success
 */
int	interpreting(char **args, char *env[])
{
	int		ret;

	if (ft_strcmp(args[0], "cd") == 0)
	{
		ft_cd(args[1], env);
		return (0);
	}
	ret = cmd_bash(args, env);
	if (g_error == INEXECVE && ret == 0)
	{
		ft_printf("%sminshell >>> %s", RED, args[0]);
		ft_printf(" command not found\n%s", WHITE);
	}
	return (1);
}
