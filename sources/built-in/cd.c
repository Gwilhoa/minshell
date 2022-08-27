/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:27:13 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/30 10:25:26 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char static	*init_path(char *arg, char **env)
{
	char	**args;
	char	*ret;

	if (arg == 0)
		return (ft_getenv("HOME", env));
	args = ft_split_bash(arg);
	ret = ft_strdup(args[0]);
	ft_free_matrix(args);
	free(args);
	if (ft_strcmp(ret, "-") == 0)
	{
		free(ret);
		ret = ft_getenv("OLDPWD", env);
	}
	return (ret);
}

void	error_path(char *args)
{
	if (args != 0 && ft_strncmp(args, "-", 2) == 0)
		ft_printf("cd: OLDPWD not set\n");
	else
		ft_printf("cd: HOME not set\n");
	g_error = 1;
}

void static	error(void)
{
	perror("cd");
	g_error = 1;
}

void	ft_cd(t_process *process, t_minishell *mini)
{
	char		*pwd;
	char		*path;

	path = init_path(process->args, mini->env);
	if (path == 0)
		error_path(process->args);
	if (chdir(path) != 0)
	{
		if (path)
			error();
		free(path);
	}
	else
	{
		pwd = getcwd(NULL, 0);
		free(path);
		path = ft_getenv("PWD", mini->env);
		if (path == NULL)
			ft_addenv(mini, "PWD=temp");
		ft_change_env("OLDPWD", path, mini);
		ft_change_env("PWD", pwd, mini);
		g_error = 0;
		free(pwd);
		free(path);
	}
}
