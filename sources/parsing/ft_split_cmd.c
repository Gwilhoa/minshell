/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:20:53 by guyar             #+#    #+#             */
/*   Updated: 2022/06/10 15:57:36 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_bash(char *str)
{
	int		nb;
	int		i;
	char	**split;
	char	*tmp;

	if (str == 0)
		return (0);
	nb = ft_nbword(str);
	split = malloc(sizeof(char *) * (nb + 1));
	nb = 0;
	i = 0;
	while (str[i] != 0)
	{
		i = ft_split_bash2(str, i, &tmp);
		ft_delquotes(&tmp);
		split[nb] = tmp;
		nb++;
		while (ft_isspace(str[i]))
			i++;
	}
	split[nb] = 0;
	return (split);
}

int	ft_nbword(char *str)
{
	int	i;
	int	q;
	int	q2;
	int	nb;

	q = 0;
	q2 = 0;
	i = 0;
	nb = 0;
	while (str[i] != 0)
	{
		if (str[i] == '"' && q != 1)
			q2 = -q2 + 1;
		else if (str[i] == '\'' && q2 != 1)
			q = -q + 1;
		if ((str[i] == ' ' || str[i] == 0) && q == 0 && q2 == 0)
		{
			nb++;
			while (str[i] == ' ')
				i++;
		}
		else
			i++;
	}
	return (nb + 1);
}

int	ft_split_bash2(char *str, int i, char **ret)
{
	char	*tmp;

	tmp = ft_substr(str, i, ft_wordlen(str, i));
	*ret = tmp;
	return (ft_wordlen(str, i));
}

int	ft_wordlen(char *str, int i)
{
	int	q;
	int	q2;

	q = 0;
	q2 = 0;
	while (str[i] != 0)
	{
		if (str[i] == '"' && q != 1)
			q2 = -q2 + 1;
		else if (str[i] == '\'' && q2 != 1)
			q = -q + 1;
		if ((str[i] == ' ' || str[i] == 0) && q == 0 && q2 == 0)
			return (i);
		i++;
	}
	return (i);
}

void	ft_delquotes(char **str)
{
	char	*tmp;
	int		i;
	int		q;
	int		q2;

	i = 0;
	q = 0;
	q2 = 0;
	tmp = *str;
	while (tmp[i] != 0)
	{
		if (tmp[i] == '"' && q != 1)
		{
			q2 = -q2 + 1;
			ft_del_char(&tmp, i);
			i--;
		}
		else if (tmp[i] == '\'' && q2 != 1)
		{
			q = -q + 1;
			ft_del_char(&tmp, i);
			i--;
		}
		if ((tmp[i] == ' ' || tmp[i] == 0) && q == 0 && q2 == 0)
			i++;
		else
			i++;
	}
	*str = tmp;
}
