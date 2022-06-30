/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:20:53 by guyar             #+#    #+#             */
/*   Updated: 2022/06/30 14:50:32 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_split_bash_2(t_split *split_struct, char *str)
{
	while (str[split_struct->i] && str)
	{
		if (str[split_struct->i] == '"' && split_struct->q[0] != 1)
			split_struct->q[1] = -split_struct->q[1] + 1;
		else if (str[split_struct->i] == '\'' && split_struct->q[1] != 1)
			split_struct->q[0] = -split_struct->q[0] + 1;
		if (str[split_struct->i] == ' ' && \
		split_struct->q[0] == 0 && split_struct->q[1] == 0)
		{
			split_struct->ret[split_struct->nb] = \
			ft_substr(str, split_struct->p, split_struct->i - split_struct->p);
			while (str[split_struct->i] == ' ' && str[split_struct->i + 1]
				&& str)
				split_struct->i++;
			split_struct->nb++;
			split_struct->p = split_struct->i;
		}
		else
			split_struct->i++;
	}
}

char	**ft_split_bash(char *str)
{
	t_split	split_struct;

	if (str == NULL)
		return (NULL);
	split_struct.nb = ft_nbword(str);
	split_struct.ret = malloc(sizeof(char *) * (split_struct.nb + 1));
	split_struct.nb = 0;
	split_struct.i = 0;
	split_struct.p = 0;
	split_struct.q[0] = 0;
	split_struct.q[1] = 0;
	ft_split_bash_2(&split_struct, str);
	split_struct.ret[split_struct.nb] = \
	ft_substr(str, split_struct.p, split_struct.p - split_struct.i);
	if (split_struct.i - 1 == split_struct.p)
	{
		free(split_struct.ret[split_struct.nb]);
		if (str[split_struct.i - 1] != ' ')
			split_struct.ret[split_struct.nb] = \
			ft_substr(str, split_struct.i - 1, 1);
		else
			split_struct.ret[split_struct.nb] = 0;
	}
	split_struct.ret[split_struct.nb + 1] = 0;
	return (split_struct.ret);
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

void static	init_var(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = -1;
}

void	ft_delquotes(char **str)
{
	char	*tmp;
	int		i;
	int		q;
	int		q2;

	init_var(&q, &q2, &i);
	tmp = *str;
	while (tmp[++i] != 0)
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
	}
	*str = tmp;
}
