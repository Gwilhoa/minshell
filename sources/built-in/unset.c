/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:44:14 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/24 15:06:11 by gchatain         ###   ########lyon.fr   */
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
		verif_args_env(args[i]);
		ft_delenv(mini, args[i]);
		i++;
	}
	ft_free_matrix(args);
	free(args);
}
