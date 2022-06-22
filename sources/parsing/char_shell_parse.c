/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_shell_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:52:15 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/22 17:10:00 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isenddollar(int c)
{
	if (ft_isalnum(c) != 1)
		return (1);
	return (0);
}

void	ft_check_dollar(char **str, char **env, int isheredoc, int error)
{
	int		i;
	char	*ret;
	int		doublequote;
	int		singlequote;

	doublequote = 0;
	singlequote = 0;
	ret = *str;
	i = 0;
	while (ret[i] != 0)
	{
		if (isheredoc == 0 && singlequote == 0 && ret[i] == '\"')
			doublequote = -doublequote + 1;
		else if (isheredoc == 0 && doublequote == 0 && ret[i] == '\'')
			singlequote = -singlequote + 1;
		else if (ret[i] == '$' && singlequote == 0)
			ft_dollar_parse(i, str, env, error);
		ret = *str;
		i++;
	}
	ret = *str;
}

void	ft_dollar_parse(int i, char **str, char **env, int error)
{
	char	*ret;
	char	*start;
	char	*end;
	char	*change;
	int		j;

	j = 0;
	ret = ft_strdup(*str);
	free(*str);
	start = ft_substr(ret, 0, i);
	j = i + 1;
	while (isenddollar(ret[j]) == 0 || (ret[j] == '?' && error))
		j++;
	change = ft_substr(ret, i + 1, j - i - 1);
	if (ft_strcmp(change, "?") == 0 && error == 1)
		change = ft_itoa(g_error);
	else
		change = ft_getenv(change, env);
	end = ft_substr(ret, j, ft_strlen(ret + j));
	if (change == NULL)
		*str = ft_strjoin_free(start, end);
	else
	{
		start = ft_strjoin_free(start, change);
		ret = ft_strjoin_free(start, end);
		*str = ret;
	}
}
