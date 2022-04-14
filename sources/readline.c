/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:23:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/14 12:56:44 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_signal(int sig)
{
	if (sig == SIGINT)
		ft_printf("\nminshell >> ");
	else if (sig == SIGQUIT)
		ft_exit();
}

int	main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;
	signal(SIGSEGV, get_signal);
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
			ret = interpreting(args, envp);
		}
	}
}

/**
 * @brief execute commands withe arguments
 * 
 * @param args 
 * @param envp 
 * @return int  0 if the commande dosen't found, 1 if success
 */
int	interpreting(char **args, char *envp[])
{
	int		ret;

	ret = cmd_bash(args, envp);
	if (ret == 0)
	{
		ft_printf("%sminshell: %s", RED, args[0]);
		ft_printf(" command not found\n%s", WHITE);
		return (0);
	}
	return (1);
}

int	cmd_bash(char **args, char *env[])
{
	char	*newargv[] = {args[0], args[1], args[2]};
	int		ret;

	ret = path_execute(args[0], newargv, env);
	return (ret);
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
