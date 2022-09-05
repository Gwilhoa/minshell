/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:42:24 by guyar             #+#    #+#             */
/*   Updated: 2022/06/28 12:18:52 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_chevron(char	*str)
{
	int	i;
	int	r;

	r = 0;
	i = 0;
	while (str && str[i] != 0)
	{
		if (str[i] == '>' || str[i] == '<')
		{
			i++;
			r++;
			if (str[i] == '>' || str[i] == '<')
				i++;
		}
		if (str[i])
			i++;
	}
	return (r);
}

char	**split_files(char	*str)
{
	int		i;
	int		j;
	char	**split;

	i = ft_count_chevron(str);
	if (i == 0)
		return (0);
	split = malloc((i + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (str[j] != 0)
	{
		if (str[j] == '>' || str[j] == '<')
		{
			split[i] = ft_cutfile(str, j);
			i++;
			j = j + ft_strlen(split[i - 1]) - 1;
		}
		j++;
	}
	split[i] = 0;
	return (split);
}

char	*ft_cutfile(char *str, int start)
{
	int	i;

	i = start + 1;
	if (str[i] == '>' || str[i] == '<')
		i++;
	while (str[i] != 0 && str[i] != '>' && str[i] != '<')
		i++;
	return (ft_substr(str, start, (i - start)));
}
