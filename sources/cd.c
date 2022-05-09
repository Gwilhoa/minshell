/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:27:13 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/09 16:05:47 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_process *process, t_minishell *mini)
{
	char		*pwd;
	char		*path;

	path = process->args;
	if (path == 0 || ft_strlen(path) == 0)
		path = ft_getenv("HOME", mini->env);
	if (path == 0)
	{
		ft_printf("no path HOME");
		return ;
	}
	if (chdir(path) != 0)
		perror("cd >>>");
	pwd = getcwd(NULL, 0);
	path = ft_getenv("PWD", mini->env);
	ft_change_env("OLDPWD", path, mini->env);
	ft_change_env("PWD", pwd, mini->env);
}
