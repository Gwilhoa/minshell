/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_shell_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:52:15 by gchatain          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/26 10:27:16 by gchatain         ###   ########lyon.fr   */
=======
/*   Updated: 2022/06/25 22:56:47 by guyar            ###   ########.fr       */
>>>>>>> c56db93e6b8bb38eb547a93ad19e3105a1210d73
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
		{
			if (ret[i + 1] != 0 && ret[i + 1] != ' ')
				ft_dollar_parse(i, str, env, error);
		}
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

	ret = ft_strdup(*str);
	free(*str);
	start = ft_substr(ret, 0, i);
	j = i + 1;
	while (isenddollar(ret[j]) == 0 || (ret[j] == '?' && error))
		j++;
	if (error == 1 && ret[j] == '?')
		change = ft_substr(ret, i, j - i);
	else
		change = ft_substr(ret, i + 1, j - i);
	if (ft_strcmp(change, "?") == 0 && error == 1)
	{
		free(change);
		change = ft_itoa(g_error);
	}
	else
	{
		end = ft_getenv(change, env);
		free(change);
		change = end;
	}
	end = ft_substr(ret, j, ft_strlen(ret + j));
	free(ret);
	*str = ft_dollar_parse_ret(start, end, change);
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
