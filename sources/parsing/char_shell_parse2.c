/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_shell_parse2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:00:32 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/04 14:42:32 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_dollar_parse_i(char *change, char *start)
{	
	int	i;

	if (change != NULL)
		i = ft_strlen(start) + ft_strlen(change);
	else
		i = ft_strlen(start);
	return (i);
}

int	ft_error_parse(int i, char **str)
{
	char	*ret;
	char	*start;
	char	*end;
	char	*change;
	int		j;

	ret = ft_strdup(*str);
	free(*str);
	start = ft_substr(ret, 0, i);
	j = i + 2;
	change = ft_substr(ret, i + 1, 1);
	change = ft_dollarenv(change, NULL, 1);
	i = ft_dollar_parse_i(change, start);
	end = ft_substr(ret, j, ft_strlen(ret + j));
	free(ret);
	*str = ft_dollar_parse_ret(start, end, change);
	ft_clean_str(str);
	return (i);
}

void	ft_check_error(char **line)
{
	int		i;
	char	*ret;
	int		doublequote;
	int		singlequote;

	doublequote = 0;
	singlequote = 0;
	ret = ft_strdup(*line);
	free(*line);
	i = 0;
	while (ret && ret[i] != 0)
	{
		if (singlequote == 0 && ret[i] == '\"')
			doublequote = -doublequote + 1;
		else if (doublequote == 0 && ret[i] == '\'')
			singlequote = -singlequote + 1;
		else if (ret[i] == '$' && singlequote == 0)
		{
			if (ret[i + 1] != 0 && ft_isspace(ret[i + 1]) != 1 && \
				ret[i + 1] == '?')
				i = ft_error_parse(i, &ret) - 1;
		}
		i++;
	}
	*line = ret;
}
