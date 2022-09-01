/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_shell_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:52:15 by gchatain          #+#    #+#             */
/*   Updated: 2022/09/01 11:49:52 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isenddollar(int c)
{
	if (ft_isalnum(c) != 1 && c != '_')
		return (1);
	return (0);
}

void	ft_check_dollar(char **str, char **env, int isheredoc)
{
	int		i;
	char	*ret;
	int		doublequote;
	int		singlequote;

	doublequote = 0;
	singlequote = 0;
	ret = ft_strdup(*str);
	free(*str);
	i = 0;
	while (ret && ret[i])
	{
		if (i < ft_strlen(ret))
		{
			if (isheredoc == 0 && singlequote == 0 && ret[i] == '\"')
				doublequote = -doublequote + 1;
			else if (isheredoc == 0 && doublequote == 0 && ret[i] == '\'')
				singlequote = -singlequote + 1;
			else if (ret[i] == '$' && singlequote == 0)
				if (ret[i + 1] != 0 && ret[i + 1] != ' ')
					i = ft_dollar_parse(i, &ret, env) - 1;
			i++;
		}
	}
	*str = ret;
}

char	*ft_dollarenv(char *str, char **env, int error)
{
	char	*ret;

	if (ft_strcmp(str, "?") == 0 && error == 1)
		ret = ft_itoa(g_error);
	else if (error == 0)
		ret = ft_getenv(str, env);
	else
		ret = ft_strjoin("$", str);
	free(str);
	return (ret);
}

int	ft_dollar_parse(int i, char **str, char **env)
{
	char	*ret;
	char	*start;
	char	*end;
	char	*change;
	int		j;

	ret = ft_strdup(*str);
	free(*str);
	start = ft_substr(ret, 0, i);
	j = i + 1;
	while (isenddollar(ret[j]) == 0)
		j++;
	change = ft_substr(ret, i + 1, j - i - 1);
	change = ft_dollarenv(change, env, 0);
	i = ft_dollar_parse_i(change, start);
	end = ft_substr(ret, j, ft_strlen(ret + j));
	free(ret);
	*str = ft_dollar_parse_ret(start, end, change);
	ft_clean_str(str);
	return (0);
}

char	*ft_dollar_parse_ret(char *start, char *end, char *change)
{
	char	*ret;

	if (change == NULL)
		ret = ft_strjoin_free(start, end);
	else
	{
		start = ft_strjoin_free(start, change);
		ret = ft_strjoin_free(start, end);
	}
	return (ret);
}
