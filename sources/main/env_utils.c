/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:13:19 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/24 14:23:25 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *key, char **env)
{
	char	**parse;
	char	*line;
	char	*temp;

	line = ft_get_line_env(key, env);
	if (line != 0)
	{
		parse = ft_split(line, '=');
		if (ft_matrix_size((const char **)parse) == 1)
			return (0);
		temp = ft_strdup(line + ft_strlen(parse[0]) + 1);
		ft_free_matrix(parse);
		free(parse);
		return (temp);
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
	return (NULL);
}

void	ft_addenv(t_minishell *mini, char *str)
{
	ft_push_back_matrix(&mini->env, str);
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
			if (newchar != NULL)
				mini->env[i] = ft_strjoin_free(mini->env[i], \
				ft_strdup(newchar));
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
	ret = malloc(ft_matrix_size((const char **)mini->env) * sizeof(char *));
	while (mini->env[++i])
	{
		if (ft_strcmp(line, mini->env[i]) == 0)
			ret[j] = mini->env[++i];
		else
			ret[j] = mini->env[i];
		if (mini->env[i] == 0)
			break ;
		j++;
	}
	ret[j] = 0;
	free(mini->env);
	free(line);
	mini->env = ret;
}
