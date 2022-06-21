/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:01:02 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/20 17:14:40 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **env)
{
	int		i;
	char	**parse;

	i = 0;
	while (env[i] != 0)
	{
		parse = ft_split(env[i], '=');
		if (parse[1] != 0)
		{
			ft_printf("%s\n", env[i]);
		}
		i++;
		ft_free_matrix(parse);
		free(parse);
	}
	exit(0);
	return ;
}
