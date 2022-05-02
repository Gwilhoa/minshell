/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:23:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/02 17:14:50 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_signal(int sig)
{
	if (sig == SIGINT)
	{
		waitpid(0, NULL, 0);
		if (g_error != INEXECVE)
		{
			ft_printf("\nminshell >> ");
			g_error = SIGC;
		}
		g_error = SIGC;
	}
	else if (sig == SIGQUIT)
	{
		ft_exit();
		g_error = SIGD;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	signal(SIGQUIT, get_signal);
	signal(SIGINT, get_signal);
	loop(envp);
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
	ft_exit();
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

	ret = cmd_bash(args, env);
	if (g_error == INEXECVE && ret == 0)
	{
		ft_printf("%sminshell: %s", RED, args[0]);
		ft_printf(" command not found\n%s", WHITE);
	}
	return (1);
}
