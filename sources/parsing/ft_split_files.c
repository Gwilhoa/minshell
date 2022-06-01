/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:42:24 by guyar             #+#    #+#             */
/*   Updated: 2022/06/01 10:15:25 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_chevron(char	*str)
{
	int	i;
	int	r;

	r = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '>' || str[i] == '<')
			r++;
		i++;
		if (str[i] == '>' || str[i] == '<')
			i++;
	}
	return (r);
}

char	**split_files(char	*str)
{
	int		i;
	int		j;
	int		f;
	char	**split;

	i = ft_count_chevron(str);
	if (i == 0)
		return (0);
	split = malloc((i + 1) + sizeof(char *));
	i = 0;
	f = 0;
	j = 1;
	while (str[++j] != 0)
	{
		if (str[j] == '>' || str[j] == '<')
		{
			split[i] = ft_substr(str, f, j - f);
			i++;
			f = j;
			j++;
		}
	}
	split[i] = ft_substr(str, f, j - f);
	split[i + 1] = 0;
	return (split);
}
