/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:02:17 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/28 17:23:42 by gchatain         ###   ########lyon.fr   */
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

int	verif_args_env(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]) == 1 || str[0] == '=')
		return (1);
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	ft_export(t_process *process, t_minishell *mini)
{
	char		**args;
	char		**arg;
	char		*env;

	arg = NULL;
	env = NULL;
	if (process->args == 0)
		prompt_export(mini->env);
	else
	{
		args = ft_split_bash(process->args);
		ft_export_loop(args, arg, env, mini);
		ft_free_matrix(args);
		free(args);
	}
}

void	ft_export_loop(char **args, char **arg, char *env, t_minishell *mini)
{
	int	i;

	i = -1;
	while (args[++i] != 0)
	{
		if (verif_args_env(args[i]) == 1)
		{
			g_error = 1;
			ft_printf("export: %s: invalid argument\n", args[i]);
			return ;
		}
		ft_delquotes(&args[i]);
		arg = ft_split(args[i], '=');
		env = ft_get_line_env(arg[0], mini->env);
		if (env == 0)
			ft_addenv(mini, args[i]);
		else if (arg[1] != 0 || ft_strcmp(args[i] \
			+ ft_strlen(args[i]) - 1, "=") == 0)
			ft_change_env(arg[0], arg[1], mini);
		ft_free_matrix(arg);
		free(arg);
	}
}
