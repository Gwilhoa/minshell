/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_shell_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:52:15 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/08 19:45:27 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isenddollar(int c)
{
	if (ft_isalnum(c) != 1)
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
	ret = *str;
	i = 0;
	while (ret[i] != 0)
	{
		if (isheredoc == 0 && singlequote == 0 && ret[i] == '\"')
		{
			ft_del_char(str, i);
			i--;
			doublequote = -doublequote + 1;
		}
		else if (isheredoc == 0 && doublequote == 0 && ret[i] == '\'')
		{
			ft_del_char(str, i);
			i--;
			singlequote = -singlequote + 1;
		}
		else if (ret[i] == '$' && singlequote == 0)
			ft_dollar_parse(i, str, env);
		ret = *str;
		i++;
	}
	ret = *str;
}

void	ft_dollar_parse(int i, char **str, char **env)
{
	char	*ret;
	char	*start;
	char	*end;
	char	*change;
	int		j;

	j = 0;
	ret = *str;
	start = ft_substr(ret, 0, i);
	j = i + 1;
	while (isenddollar(ret[j]) == 0)
		j++;
	change = ft_substr(ret, i + 1, j - i - 1);
	change = ft_getenv(change, env);
	end = ft_substr(ret, j, ft_strlen(ret + j));
	start = ft_strjoin(start, change);
	ret = ft_strjoin(start, end);
	*str = ret;
}

void	ft_del_char(char **str, int index)
{
	char	*start;
	char	*end;

	start = ft_substr(*str, 0, index);
	end = ft_substr(*str, index + 1, ft_strlen(*str));
	*str = ft_strjoin(start, end);
	free(start);
	free(end);
}
