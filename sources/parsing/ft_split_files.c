/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:42:24 by guyar             #+#    #+#             */
/*   Updated: 2022/05/23 17:30:36 by guyar            ###   ########.fr       */
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
	int		nb;
	char	**split;

	nb = ft_count_chevron(str);
	split = malloc((nb + 1) + sizeof(char *));
	i = 0;
	f = 0;
	j = 2;
	while (str[j] != 0)
	{
		if (str[j] == '>' || str[j] == '<')
		{
			split[i] = ft_substr(str, f, j - f);
			i++;
			f = j;
			j++;
		}
		j++;
	}
	split[i] = ft_substr(str, f, j);
	split[i + 1] = 0;
	return (split);
}