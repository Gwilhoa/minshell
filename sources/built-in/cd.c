/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:27:13 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/16 15:18:34 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_process *process, t_minishell *mini)
{
	char		*pwd;
	char		*path;

	if (process->args == 0)
		path = ft_getenv("HOME", mini->env);
	else
		path = ft_strdup(process->args);
	if (path == 0)
	{
		ft_printf("cd >> no path HOME\n");
		return ;
	}
	if (chdir(path) != 0)
		perror("cd >>>");
	pwd = getcwd(NULL, 0);
	free(path);
	path = ft_getenv("PWD", mini->env);
	ft_change_env("OLDPWD", path, mini);
	ft_change_env("PWD", pwd, mini);
	return ;
}
