/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:27:13 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/04 12:16:27 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char *args, char **env)
{
	char	*pwd;

	if (args == 0)
		args = ft_getenv("HOME", env);
	if (args == 0)
		return ;
	if (chdir(args) != 0)
		perror("cd :");
	pwd = getcwd(NULL, 0);
	ft_change_env("OLDPWD", ft_getenv("PWD", env), env);
	ft_change_env("PWD", pwd, env);
}
