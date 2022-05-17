/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:13:19 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/16 16:50:29 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *key, char **env)
{
	char	**parse;
	char	*line;

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

void	ft_addenv(t_minishell *mini, char *str)
{
	int		size;
	char	**ret;
	int		i;

	i = 0;
	size = ft_matrixlen(mini->env);
	ret = malloc((size + 2) * sizeof(char *));
	while (mini->env[i] != 0)
	{
		ret[i] = mini->env[i];
		i++;
	}
	ret[i] = str;
	ret[i + 1] = 0;
	free(mini->env);
	mini->env = ret;
}

void	ft_change_env(char *key, char *newchar, t_minishell *mini)
{
	int		i;
	char	**parse;

	i = 0;
	while (mini->env[i] != 0)
	{
		parse = ft_split(mini->env[i], '=');
		if (ft_strcmp(key, parse[0]) == 0)
		{
			free(mini->env[i]);
			mini->env[i] = ft_strjoin(key, "=");
			mini->env[i] = ft_strjoin_free(mini->env[i], ft_strdup(newchar));
			ft_free_matrix(parse);
			free(parse);
			return ;
		}
		ft_free_matrix(parse);
		free(parse);
		i++;
	}
	return ;
}

void	ft_delenv(t_minishell *mini, char *key)
{
	int		i;
	int		j;
	char	**ret;
	char	*line;

	i = -1;
	j = 0;
	line = ft_get_line_env(key, mini->env);
	if (line == 0)
		return ;
	ret = malloc(ft_matrixlen(mini->env) * sizeof(char *));
	while (mini->env[++i])
	{
		if (ft_strcmp(line, mini->env[i]) == 0)
			ret[j] = mini->env[++i];
		else
			ret[j] = mini->env[i];
		j++;
	}
	ret[j] = 0;
	free(mini->env);
	free(line);
	mini->env = ret;
}
