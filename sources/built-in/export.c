/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:02:17 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/08 12:37:21 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_process *process, t_minishell *mini)
{
	int			i;
	char		**args;
	char		**arg;
	char		*env;
	char		*tmp;

	i = -1;
	if (process->args == 0)
	{
		while (mini->env[++i] != 0)
		{
			tmp = ft_split(mini->env[i], '=')[0];
			if (ft_getenv(tmp, mini->env) != NULL)
				ft_printf("declare -x %s=\"%s\"\n", tmp, ft_getenv(tmp, mini->env));
			else if (ft_strlen(ft_get_line_env(tmp, mini->env)) > ft_strlen(tmp))
				ft_printf("declare -x %s=\"\"\n", tmp);
			else
				ft_printf("declare -x %s\n", tmp);
		}
	}
	else
	{
		args = ft_split(process->args, ' ');
		while (args[++i] != 0)
		{
			arg = ft_split(args[i], '=');
			env = ft_get_line_env(arg[0], mini->env);
			if (env == 0)
				ft_addenv(mini, args[i]);
			else if (arg[1] != 0)
				ft_change_env(arg[0], arg[1], mini);
		}
	}
}
