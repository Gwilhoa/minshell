/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:44:14 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/22 19:07:17 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_process *process, t_minishell *mini)
{
	char	**args;
	int		i;

	i = 0;
	if (process->args == 0)
		return ;
	args = ft_split(process->args, ' ');
	while (args[i] != 0)
	{
		ft_delenv(mini, args[i]);
		i++;
	}
	ft_free_matrix(args);
	free(args);
}
