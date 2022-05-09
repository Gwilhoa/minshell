/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:02:17 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/09 15:01:42 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(t_process *process, t_minishell *mini)
{
	int			i;
	char		**args;
	char		**arg;
	char		*env;

	i = 0;
	if (process->args == 0)
	{
		while (mini->env[i] != 0)
		{
			ft_printf("declare -x %s\n", mini->env[i]);
			i++;
		}
	}
	else
	{
		args = ft_split(process->args, ' ');
		while (args[i] != 0)
		{
			arg = ft_split(args[i], '=');
			env = ft_get_line_env(arg[0], mini->env);
			if (env == 0)
			{
				ft_addenv(args[i], mini->env);
			}
			else if (arg[1] != 0)
				ft_change_env(arg[0], arg[1], mini->env);
			i++;
		}
	}
	return (0);
}
