/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:26:20 by guyar             #+#    #+#             */
/*   Updated: 2022/06/29 11:24:35 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void static	init_var(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = -1;
	*d = 0;
}

int	ft_nbcmd(char *str)
{
	int	q;
	int	q2;
	int	i;
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
		if (str[i] == '|' && q == 0 && q2 == 0)
			nb++;
		i++;
	}
	return (nb + 1);
}

int	ft_check_syntaxe(char *str)
{
	int		i;
	int		r;
	int		q;
	int		q2;
	char	*temp;

	init_var(&q, &q2, &i, &r);
	temp = ft_strtrim((const char *) str, " ");
	if (ft_strlen(temp) == 0)
	{
		free(temp);
		return (-2);
	}
	while (temp[++i])
	{
		if (temp[i] == '"' && q != 1)
			q2 = -q2 + 1;
		else if (temp[i] == '\'' && q2 != 1)
			q = -q + 1;
	}
	if (q != 0 || q2 != 0 || (i > 0 && (temp[i - 1] == '|')) || \
		(i > 0 && (temp[i - 1] == '\\')) || temp[0] == '|')
		r = -1;
	free(temp);
	return (r);
}
