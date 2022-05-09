/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:13:19 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/09 16:06:05 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *key, char **env)
{
	int		i;
	char	**parse;
	char	*line;

	i = 0;
	line = ft_get_line_env(key, env);
	if (line != 0)
	{
		parse = ft_split(line, '=');
		free(parse[0]);
		free(parse);
		return (parse[1]);
	}
	return (NULL);
}

char	*ft_get_line_env(char *key, char **env)
{
	int		i;
	char	**parse;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strcmp(env[i], "") != 0)
		{
			parse = ft_split(env[i], '=');
			if (ft_strcmp(key, parse[0]) == 0)
			{
				ft_free_matrix(parse);
				free(parse);
				return (env[i]);
			}
			i++;
			ft_free_matrix(parse);
			free(parse);
		}
		else
			i++;
	}
	return (NULL);
}

void	ft_env(char **env)
{
	int		i;
	char	**parse;

	i = 0;
	while (env[i] != 0)
	{
		parse = ft_split(env[i], '=');
		if (parse[1] != 0)
		{
			ft_printf("%s\n" , env[i]);
		}
		i++;
		ft_free_matrix(parse);
		free(parse);
	}
	return ;
}

void	ft_addenv(char *str, char **env)
{
	int	size;

	size = ft_matrixlen(env);
	env[size] = str;
	env[size + 1] = 0;
}

void	ft_change_env(char *key, char *newchar, char **env)
{
	int		i;
	char	**parse;

	i = 0;
	while (env[i] != 0)
	{
		parse = ft_split(env[i], '=');
		if (ft_strcmp(key, parse[0]) == 0)
		{
			free(env[i]);
			env[i] = ft_strjoin(key, "=");
			env[i] = ft_strjoin_free(env[i], newchar);
			return ;
		}
		ft_free_matrix(parse);
		free(parse);
		i++;
	}
	return ;
}

void	ft_delenv(t_minishell *mini, char	*key)
{
	int		i;
	int		j;
	char	**ret;
	char	*line;


	i = 0;
	j = 0;
	line = ft_get_line_env(key, mini->env);
	ret = malloc(ft_matrixlen(mini->env) * sizeof(char *));
	while (mini->env[i])
	{
		if (ft_strcmp(line, mini->env[i]) == 0)
		{
			i++;
			ret[j] = mini->env[i];
		}
		else
			ret[j] = mini->env[i];
		i++;
		j++;
	}
	free(mini->env);
	mini->env = ret;
}
