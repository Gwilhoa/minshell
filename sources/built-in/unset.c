/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:44:14 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/30 11:01:08 by gchatain         ###   ########lyon.fr   */
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
	exit(0);
}
