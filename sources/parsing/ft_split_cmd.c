/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:20:53 by guyar             #+#    #+#             */
/*   Updated: 2022/06/09 22:20:34 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_split_cmd(char *str)
{
	int i;
	char **split;
	int start;
	int end;
	
	start = 0;
	end = 0; 
	i = ft_nbword(str);
	split = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (i < ft_nbword(str))
	{
		start = ft_wordstart(str, end);
		end = ft_wordend(str, start);
		dprintf(2, "start = %d\n", start);
		dprintf(2, "end = %d\n", end);
		split[i] = ft_substr(str, start, (end + 1)  - start);
		i++;
	}
	split[i] = 0;
	return (split);
}

int ft_wordstart(char *str, int i)
{
	if (i != 0)
		i++;
	while (str[i] == ' ' && str[i])
		i++;
	return (i);
}

int ft_wordend(char *str, int i)
{
	if (str[i] == '"')
	{
		i++;
		while (str[i] != '"')
			i++;
		return(i);
	}
	if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\'')
			i++;
		return(i);
	}
	while (str[i] != ' ' && str[i])
		i++;
	return(i);
}


int ft_nbword(char *str)
{
	int i; 
	int q;
	int q2;
	int nb;
	
	q = 0;
	q2 = 0;
	i = 0;
	nb = 0;
	while(str[i] == ' ')
		i++;
	while(str[i])
	{
		if (str[i] == '"' && q != 1)
		{
			q2++;	
			if (q2 == 2)
				q2 = 0;
		}
		if (str[i] == '\'' && q2 != 1)
		{
			q++;
			if (q == 2)
				q = 0;
		}
		if ((str[i] == ' ' && str[i + 1] != ' '
			&& q == 0 && q2 == 0)
			|| (!str[i + 1]))
			nb++;
		i++;
	}
	return (nb);
}