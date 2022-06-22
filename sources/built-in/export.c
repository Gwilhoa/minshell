/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:02:17 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/22 19:05:23 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void static	prompt_export(char **env)
{
	int		i;
	char	*tmp;
	char	*var;

	i = 0;
	while (env[++i] != 0)
	{
		tmp = ft_split(env[i], '=')[0];
		var = ft_getenv(tmp, env);
		if (var != NULL)
		{
			ft_printf("declare -x %s=\"%s\"\n", tmp, ft_getenv(tmp, env));
			free(var);
		}
		else if (ft_strlen(ft_get_line_env(tmp, env)) > ft_strlen(tmp))
			ft_printf("declare -x %s=\"\"\n", tmp);
		else
			ft_printf("declare -x %s\n", tmp);
		free(tmp);
	}
}

void	ft_export(t_process *process, t_minishell *mini)
{
	int			i;
	char		**args;
	char		**arg;
	char		*env;

	i = -1;
	if (process->args == 0)
		prompt_export(mini->env);
	else
	{
		args = ft_split_bash(process->args);
		while (args[++i] != 0)
		{
			ft_delquotes(&args[i]);
			arg = ft_split(args[i], '=');
			env = ft_get_line_env(arg[0], mini->env);
			if (env == 0)
				ft_addenv(mini, args[i]);
			else if (arg[1] != 0)
				ft_change_env(arg[0], arg[1], mini);
		}
		ft_free_matrix(args);
		free(args);
		ft_free_matrix(arg);
		free(arg);
	}
}
