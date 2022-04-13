/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:23:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/13 14:05:32 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_signal(int sig)
{
	if (sig == SIGINT)
		ft_printf("\nminshell >> ");
}

int	main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
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
		line = readline("minshell >> ");
		if (line[0] != 0)
		{	
			add_history(line);
			args = ft_split(line, ' ');
			ret = getcmd(args, envp);
			if (ret == 0)
			{
				ft_printf("%sminshell: %s", RED, line);
				ft_printf(" command not found\n%s", WHITE);
			}
			if (ret == -1)
				return (0); //programme de sortie
		}
	}
}

/**
 * @brief program's center
 * 
 * @param args argument's command
 * @return int (return 0 if the command does'nt exist)
 */
int	getcmd(char **args, char *envp[])
{
	if (args == 0)
		return (0);
	if (cmd_bash(args, envp) == 1)
	{
		return (1);
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

int	cmd_bash(char **args, char *env[])
{
	char	*newargv[] = {args[0], args[1], args[2]};

	return (path_execute(args[0], newargv, env));
}

int	path_execute(char *cmd, char *args[], char *env[])
{
	char	**path;
	int		size;
	int		i;
	int		pid;
	int		res;
	int		status;
	char	*format;

	i = 0;
	res = -1;
	path = ft_split(getenv("PATH"), ':');
	size = ft_matrixlen((const char **)path);
	while (i < size)
	{
		status = -1;
		format = ft_strjoin(path[i], "/");
		format = ft_strjoin(format, cmd);
		pid = fork();
		if (pid == 0)
		{
			res = execve(format, args, env);
			if (res != -1)
				exit(0);
			exit(1);
		}
		waitpid(pid, &status, 0);
		if (status == 0)
			return (1);
		i++;
	}
	pid = fork();
	if (pid == 0)
	{
		res = execve(cmd, args, env);
		if (res != -1)
			exit(0);
		exit(1);
	}
	waitpid(pid, &status, 0);
	if (status == 0)
		return (1);
	return (0);
}
