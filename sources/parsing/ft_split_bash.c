/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:20:53 by guyar             #+#    #+#             */
/*   Updated: 2022/06/17 03:54:18 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_bash(char *str)
{
	char	**ret;
	int		nb;
	int		i;
	int		p;
	int		q;
	int		q2;

	if (str == NULL)
		return (NULL);
	nb = ft_nbword(str);
	ret = malloc(sizeof(char *) * (nb + 1));
	nb = 0;
	i = 0;
	p = 0;
	q = 0;
	q2 = 0;
	while (str[i])
	{
		if (str[i] == '"' && q != 1)
			q2 = -q2 + 1;
		else if (str[i] == '\'' && q2 != 1)
			q = -q + 1;
		if (str[i] == ' ' && q == 0 && q2 == 0)
		{
			ret[nb] = ft_substr(str, p, i - p);
			while (str[i] == ' ')
				i++;
			nb++;
			p = i;
		}
		i++;
	}
	ret[nb] = ft_substr(str, p, p - i);
	if (i - 1 == p)
	{
		if (str[i - 1] != ' ')
			ret[nb] = ft_substr(str, i - 1, 1);
		else
			ret[nb] = 0;
	}
	ret[nb + 1] = 0;
	return (ret);
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
	nb = 1;
	while (str[i])
	{
		if (str[i] == '"' && q != 1)
			q2 = -q2 + 1;
		else if (str[i] == '\'' && q2 != 1)
			q = -q + 1;
		if (str[i] == ' ' && q == 0 && q2 == 0)
			nb++;
		i++;
	}
	return (nb);
}

void	ft_delquotes(char **str)	// leaks here ?
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
			ft_delchar(&tmp, i);
			i--;
		}
		else if (tmp[i] == '\'' && q2 != 1)
		{
			q = -q + 1;
			ft_delchar(&tmp, i);
			i--;
		}
		if ((tmp[i] == ' ' || tmp[i] == 0) && q == 0 && q2 == 0)
			i++;
		else
			i++;
	}
	*str = tmp;
}
