/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:13:19 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/04 13:35:10 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *key, char **env)
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
				return (parse[1]);
			i++;
		}
		else
			i++;
	}
	return (NULL);
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
			env[i] = ft_strjoin(key, "=");
			env[i] = ft_strjoin(env[i], newchar);
		}
		i++;
	}
	return ;
}
