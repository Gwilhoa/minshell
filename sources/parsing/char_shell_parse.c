/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_shell_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:52:15 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/17 13:26:00 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_string(char **str, char **env)
{
	int		i;
	int		f;
	char	*ret;

	ret = *str;
	i = 0;
	f = 0;
	while (ret[i] != 0)
	{
		if (ret[i] == '\'')
			f = -f + 1;
		else if (ret[i] == '~' && f == 0)
			ret = ft_tilde_parse(i, ret, env);
		else if (ret[i] == '$' && f == 0)
			ret = ft_dollar_parse(i, ret, env);
		i++;
	}
	if (ft_strcmp(ret, "") == 0)
		*str = NULL;
	else
		*str = ret;
}

char	*ft_tilde_parse(int i, char *ret, char **env)
{
	char	*start;
	char	*change;
	char	*end;
	char	*str;

	if (i != 0)
	start = ft_substr(ret, 0, i);
	else
	{
		start = malloc(1);
		start[0] = 0;
	}
	change = ft_getenv("HOME", env);
	end = ft_substr(ret, i +1, ft_strlen(ret));
	str = ft_strjoin(ft_strjoin(start, change), end);
	return (str);
}

char	*ft_dollar_parse(int i, char *ret, char **env)
{
	char	*start;
	char	*end;
	char	*change;
	int		j;

	if (i != 0)
		start = ft_substr(ret, 0, i);
	else
	{
		start = malloc(1);
		start[0] = 0;
	}
	change = ft_getchange(i, ret, env);
	j = i;
	while (ret[j] != ' ' && ret[j] != 0)
		j++;
	i = i + j;
	end = ft_substr(ret, i, ft_strlen(ret));
	if (end == NULL)
	{
		end = malloc(1);
		end[0] = 0;
	}
	ret = ft_strjoin(ft_strjoin(start, change), end);
	return (ret);
}

char	*ft_getchange(int i, char *ret, char **env)
{
	int		f;
	char	*change;

	f = i;
	while (ret[i] != ' ' && ret[i] != 0)
		i++;
	change = ft_substr(ret, f + 1, i - f - 1);
	change = ft_getenv(change, env);
	if (change == NULL)
	{
		change = malloc(1);
		change[0] = 0;
	}
	return (change);
}
