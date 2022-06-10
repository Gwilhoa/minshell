/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:26:20 by guyar             #+#    #+#             */
/*   Updated: 2022/06/10 18:28:09 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	int	i;
	int	q;
	int	q2;

	q = 0;
	q2 = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' && q != 1)
			q2 = -q2 + 1;
		else if (str[i] == '\'' && q2 != 1)
			q = -q + 1;
		i++;
	}
	if (q != 0 || q2 != 0 || str[-1] == '|')
		return (-1);
	return (0);
}
