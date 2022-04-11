/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:23:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/11 10:50:40 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_signal(int sig)
{
		(void) sig;
	ft_printf("\nminshell >>");
}

int	main(void)
{
	signal(SIGINT, get_signal);
	loop();
	return (0);
}

int	loop(void)
{
	STRING	line;
	char	**args;
	int		ret;
	while (1)
	{
		line = readline("minshell >> ");
		if (line[0] != 0)
		{	
			add_history(line);
			args = ft_split(line, ' ');
			ret = getcmd(args);
			if (ret == 0)
			{
				ft_printf("%sminshell: %s", RED, line);
				ft_printf(" command not found\n%s", WHITE);
			}
			//penser a free args
			if (ret == -1)
				return (0);
		}
	}
}

/**
 * @brief program's center
 * 
 * @param args argument's command
 * @return int (return 0 if the command does'nt exist)
 */
int	getcmd(char **args)
{

	if (args == 0)
		return (0);
	if (cmd_bash(args) != 0)
	{
		return 1;
	}
	if (ft_strncmp(args[0], "pwd", 3) == 0)
	{
		ft_pwd();
	}
	if (ft_strncmp(args[0], "exit", 4) == 0)
	{
		return -1;
	}
	return (0);
}

/**
 * @brief function to know if the string is a redirecting bash
 * 
 * @param str (at comparate)
 * @return int (1 is redirecting)
 */
int	ft_isredirecting(const STRING str)
{
	if (ft_strncmp(str, ">", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, ">>", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "<", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "<<", ft_strlen(str)) == 0)
		return (1);
	return (0);
}


int	cmd_bash()
{
	return (0);
}